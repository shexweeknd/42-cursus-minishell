/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 05:51:07 by ballain           #+#    #+#             */
/*   Updated: 2024/08/24 09:23:04 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_getline(void)
{
	return (0);
}

// #include "minishell.h"

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
// 		printf("PROMPT	: [%s]\n", prompt);
// 		cmd = ft_get_cmds(prompt);
// 		ft_show_cmd(cmd);
// 		if (ft_strcmp(prompt, "exit") == 0)
// 		{
// 			free(prompt);
// 			ft_free_cmds(cmd);
// 			break ;
// 		}
// 		id = fork();
// 		if (id == 0)
// 		{
// 			// ft_multi_pipe(cmd, venv, envp);
// 			path = ft_get_env_var(venv, "PATH")->content;
// 			printf("PAT LEN	: [%d]\n", ft_lst_content_len(path) + (ft_lstsize(path) - 1));
// 			printf("VAR LEN	: [%d]\n", ft_new_arg_len(cmd->args[1], venv));
// 			ft_free_cmds(cmd);
// 			free(prompt);
// 			break ;
// 		}
// 		else
// 		{
// 			wait(NULL);
// 			ft_free_cmds(cmd);
// 			free(prompt);
// 		}
// 	}
// 	// ft_exec_cmds(cmd, venv, envp);
// 	ft_free_env(venv);
// 	return 0;
// }
