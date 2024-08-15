/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:38:58 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/15 10:05:50 by ballain          ###   ########.fr       */
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

void	ft_print_env(t_env_var *env)
{
	printf("\033[0;4;32m%s          \033[0;0m :\n", env->name);
	ft_show_list(env->content);
}

void	ft_show_env(t_env_var *env)
{
	printf("\033[0;4;31mENV VARIABLE       : \033[0;0m\n");
	_loop((void **)&env, (t_lst_utils){0, ft_print_env, _next_env});
}

// test de la fonction get_history
int	main(int argc, char const **argv, char **env)
{
	t_env_var	*venv;

	(void)argc;
	(void)argv;
	if (argc == 2)
	{
		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	else
	{
		venv = ft_get_env(env);
		ft_show_env(venv);
		ft_free_env(venv);
	}
	// (void)env;
	// char	*tmp;
	// int		len;

	// len = 0;
	// tmp = ft_strdup("test:");
	// len = sizeof(tmp) / sizeof(char *);
	// printf("LEN	: [%d]\n", len);
	return (0);
}