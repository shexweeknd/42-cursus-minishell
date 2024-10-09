/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:43:49 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/09 09:24:50 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

void	recurse_free_hd(t_hd *hd)
{
	if (!hd)
	{
		free(hd);
		return ;
	}
	recurse_free_hd(hd->next);
	free(hd);
	return ;
}

void	recurse_close_hd(t_hd *hd)
{
	if (!hd)
		return ;
	close(hd->fd[0]);
	close(hd->fd[1]);
	recurse_close_hd(hd->next);
	return ;
}
