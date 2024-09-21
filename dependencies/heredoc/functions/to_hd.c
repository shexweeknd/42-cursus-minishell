/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:32:19 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/21 09:58:27 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

void	init_hd(t_hd *hd, char *eof)
{
	if (hd)
		return ;
	hd = (t_hd *)malloc(sizeof(hd));
	if (!hd)
		return ;
	pipe(hd->fd);
	hd->pos = 0;
	fullfill_fd(hd->fd[1], eof);
	hd->next = NULL;
}

void	add_hd(t_hd *hd, char *eof)
{
	int	pos;

	pos = 0;
	while (hd->next)
	{
		hd = hd->next;
		pos++;
	}
	hd->next = (t_hd *)malloc(sizeof(hd));
	if (!hd->next)
		return ;
	hd = hd->next;
	pipe(hd->fd);
	hd->pos = pos + 1;
	fullfill_fd(hd->fd[0], eof);
	hd->next = NULL;
}

t_hd	*hd_cmd(char cmd, char *eof)
{
	static t_hd	*hd = NULL;

	if (cmd == 'g')
		return (hd);
	if (cmd == 'i')
		return (init_hd(hd, eof), hd);
	if (cmd == 'a')
		return (add_hd(hd, eof), hd);
	if (cmd == 'f')
		return (recurse_free_hd(hd), NULL);
	return (NULL);
}
