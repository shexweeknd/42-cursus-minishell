/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:54:12 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/13 12:54:43 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void	free_history(t_hist_elem *hist_elem)
{
	t_hist_elem	*suivant;

	while (hist_elem)
	{
		suivant = hist_elem->next;
		free(hist_elem);
		hist_elem = suivant;
	}
	return ;
}
