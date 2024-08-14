/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_debug_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:52:55 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/14 15:18:36 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void	print_history(t_hist_elem *hist_elem)
{
	while (hist_elem)
	{
		printf("command is: %s\n", hist_elem->command);
		if (hist_elem->is_offset_to_write)
			printf("is_offset: YES\n\n");
		else
			printf("is_offset: NO\n\n");
		hist_elem = hist_elem->next;
	}
}
