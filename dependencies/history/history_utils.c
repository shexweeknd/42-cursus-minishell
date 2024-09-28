/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:54:12 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/28 07:01:19 by hramaros         ###   ########.fr       */
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
		hist_elem = NULL;
		return ;
	}
	rl_clear_history();
	free_lchistory(hist_elem->next);
	free(hist_elem->command);
	free(hist_elem);
	hist_elem = NULL;
	return ;
}
