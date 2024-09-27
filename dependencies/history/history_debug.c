/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:52:55 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/27 08:39:27 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void	display_lchist(t_hist_elem *hist_elem)
{
	printf("\033[32m[PRINTING LOCAL HISTORY]: \033[0m\n");
	while (hist_elem)
	{
		printf("\033[32mCommand \033[0m: %s\n", hist_elem->command);
		printf("\033[32mLine number \033[0m: %d\n", hist_elem->line_nbr);
		printf("\033[32mIs offset \033[0m: %d\n\n", hist_elem->is_offset);
		hist_elem = hist_elem->next;
	}
}

void	show_formatted_lchist(t_hist_elem *lchist)
{
	int	i;

	if (lchist)
	{
		i = 0;
		while (lchist)
		{
			printf("%4d %s\n", i + 1, lchist->command);
			i++;
			lchist = lchist->next;
		}
	}
}
