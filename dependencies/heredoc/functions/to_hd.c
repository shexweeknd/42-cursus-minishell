/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:32:19 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/10 12:27:19 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

void	init_hd(t_hd **hd_addr, t_eofs *eof)
{
	t_hd	*hd;

	hd = *hd_addr;
	if (hd)
		return ;
	hd = (t_hd *)malloc(sizeof(t_hd));
	if (!hd)
		return ;
	pipe(hd->fd);
	hd->pos = 0;
	hd->size = fullfill_fd(hd->fd[1], eof);
	hd->next = NULL;
	*hd_addr = hd;
}

static void	add_hd(t_hd **hd_addr, t_eofs *eof)
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
	hd->next = (t_hd *)malloc(sizeof(t_hd));
	if (!hd->next)
		return ;
	hd = hd->next;
	pipe(hd->fd);
	hd->pos = pos + 1;
	hd->size = fullfill_fd(hd->fd[1], eof);
	hd->next = NULL;
}

t_hd	*hd_cmd(char cmd, t_eofs *eof)
{
	static t_hd	*hd;

	if (cmd == 'g')
		return (hd);
	if (cmd == 'i')
		return (init_hd(&hd, eof), hd);
	if (cmd == 'a')
		return (add_hd(&hd, eof), hd);
	if (cmd == 'f' && hd)
		return (recurse_free_hd(hd), hd = NULL, NULL);
	if (cmd == 'p')
		return (print_hd(hd), NULL);
	return (NULL);
}
