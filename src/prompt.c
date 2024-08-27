/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 05:51:07 by ballain           #+#    #+#             */
/*   Updated: 2024/08/27 15:39:47 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_getline(void)
{
	return (0);
}

#include "minishell.h"

// int	main(int argc, char const *argv[], char **envp)
// {
// 	(void)argc;
// 	(void)argv;
// 	// (void)envp;
// 	t_cmd		*cmd;
// 	t_env_var	*venv;
// 	t_list		*path;
// 	char		*prompt;
// 	int			id;

// 	prompt = NULL;
// 	venv = ft_get_env(envp);
// 	while (1)
// 	{
// 		prompt = readline("ballain@ > ");
// 		if (ft_strcmp(prompt, "exit") == 0)
// 		{
// 			free(prompt);
// 			break ;
// 		}
// 		cmd = ft_get_cmds(prompt);
// 		ft_show_cmd(cmd);
// 		id = fork();
// 		if (id == 0)
// 		{
// 			// ft_multi_pipe(cmd, venv, envp);
// 			path = ft_get_env_var(venv, "PATH")->content;
// 			printf("PAT LEN	: [%d]\n", ft_lst_content_len(path) + (ft_lstsize(path) - 1));
			
// 			printf("--------------------------------\n");
// 			ft_analyse_args(cmd, venv, ft_analyse_arg);
// 			// ft_show_cmd(cmd);
// 			printf("--------------------------------\n");
			
// 			ft_free_cmds(cmd);
// 			free(prompt);
// 			break ;
// 		}
// 		else
// 		{
// 			wait(NULL);
// 			free(prompt);
// 		}
// 	}
// 	if (id != 0)
// 	{
// 		printf("\n\n\nEND\n");
// 		ft_show_cmd(cmd);
// 		ft_free_cmds(cmd);
// 	}
// 	// ft_exec_cmds(cmd, venv, envp);
// 	ft_free_env(venv);
// 	return 0;
// }
