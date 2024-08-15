/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:54:12 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/13 15:21:45 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void	free_history(t_hist_elem *hist_elem)
{
	if (!hist_elem)
		return ;
	if (!hist_elem->next)
	{
		free(hist_elem->command);
		free(hist_elem);
		return ;
	}
	free_history(hist_elem->next);
	free(hist_elem->command);
	free(hist_elem);
	return ;
}