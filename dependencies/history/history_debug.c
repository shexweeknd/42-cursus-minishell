/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:52:55 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/16 16:08:47 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void	display_lchistory(t_hist_elem *hist_elem)
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

void	display_rlhistory(void)
{
	HIST_ENTRY	**hist_list;
	int			i;

	printf("\033[31m[PRINTING READLINE HISTORY]: \033[0m\n");
	i = 0;
	hist_list = history_list();
	if (hist_list)
	{
		while (hist_list[i])
		{
			printf("\033[31mCommand \033[0m: %s\n", hist_list[i]->line);
			printf("\033[31mLine number \033[0m: %d\n\n", i);
			i++;
		}
	}
}
