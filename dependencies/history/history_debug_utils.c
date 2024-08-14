/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_debug_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:52:55 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/14 12:15:18 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void	print_history(t_hist_elem *hist_elem)
{
	while (hist_elem)
	{
		printf("%s\n", hist_elem->command);
		hist_elem = hist_elem->next;
	}
}
