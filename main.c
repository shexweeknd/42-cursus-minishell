/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:38:58 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/13 11:38:59 by hramaros         ###   ########.fr       */
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
	(void)argc;
	(void)env;
	(void)argv;
	get_history("~/.bash_history");
	return (0);
}
