/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:38:58 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/13 15:22:58 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_show_list(t_list *list)
{
	while (list)
	{
		printf("	- %s\n", (char *)list->content);
		list = list->next;
	}
}

int	main(int argc, char const **argv, char **env)
{
	t_hist_elem	*result;

	(void)argc;
	(void)env;
	(void)argv;
	result = get_history("/home/hramaros/Documents/Cursus/Cursus_42/Minishell/dependencies/history/src/history_test.txt");
	print_history(result);
	free_history(result);
	return (0);
}
