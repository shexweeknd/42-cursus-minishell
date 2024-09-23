/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:32:19 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/23 10:12:32 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

void	init_hd(t_hd **hd_addr, char *eof)
{
	t_hd	*hd;

	hd = *hd_addr;
	if (hd)
		return ;
	hd = (t_hd *)malloc(sizeof(hd));
	if (!hd)
		return ;
	pipe(hd->fd);
	hd->pos = 0;
	hd->size = fullfill_fd(hd->fd[1], eof);
	hd->next = NULL;
	*hd_addr = hd;
}

void	add_hd(t_hd **hd_addr, char *eof)
{
	t_hd	*hd;
	int		pos;

	hd = *hd_addr;
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
	hd->size = fullfill_fd(hd->fd[1], eof);
	hd->next = NULL;
}

t_hd	*hd_cmd(char cmd, char *eof)
{
	static t_hd	*hd;

	if (cmd == 'g')
		return (hd);
	if (cmd == 'i')
	{
		init_hd(&hd, eof);
		return (hd);
	}
	if (cmd == 'a')
		return (add_hd(&hd, eof), hd);
	if (cmd == 'f')
		return (recurse_free_hd(hd), NULL);
	if (cmd == 'p')
		return (print_hd(hd), NULL);
	return (NULL);
}
