/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 08:48:28 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/24 15:19:55 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

void	putstr_from_fd(int fd, int size)
{
	char	c;

	while (size && read(fd, &c, 1) > 0 && c)
	{
		write(STDOUT_FILENO, &c, 1);
		size--;
	}
}

void	print_hd(t_hd *hd)
{
	while (hd)
	{
		printf("\n");
		printf("[hd nbr]: %d\n", hd->pos);
		write(STDOUT_FILENO, "[hd content]:\n", 15);
		write(STDOUT_FILENO, "------\n", 8);
		putstr_from_fd(hd->fd[0], hd->size);
		write(STDOUT_FILENO, "------\n", 8);
		printf("\n");
		hd = hd->next;
	}
}
