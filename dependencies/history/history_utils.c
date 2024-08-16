/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:54:12 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/16 15:34:14 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void	*get_next_history(t_hist_elem *src)
{
	return (src->next);
}

void	add_back_history(t_hist_elem *src, t_hist_elem *new)
{
	src->next = new;
}

void	free_lchistory(t_hist_elem *hist_elem)
{
	if (!hist_elem)
		return ;
	if (!hist_elem->next)
	{
		free(hist_elem->command);
		free(hist_elem);
		return ;
	}
	free_lchistory(hist_elem->next);
	free(hist_elem->command);
	free(hist_elem);
	return ;
}
