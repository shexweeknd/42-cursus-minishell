/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:55:43 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/11 14:34:55 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_prompt	prompt;
	t_cmd		*cmd;
	t_hist_elem	*hist;
	t_env		*venv;

	((void)argc, (void)argv);
	(venv = ft_getenv(envp), hist = get_history(HIST_PATH),
		init_prompt(&prompt));
	while (1)
	{
		(setup_main_signals(), get_prompt(&prompt, MSH_NAME));
		if (prompt.line == NULL)
			continue ;
		hist = ft_append_hist_elem(hist, ft_strdup(prompt.line));
		if (strcmp(prompt.line, "exit") == 0 || prompt.to_exit)
			return (printf("exit\n"), set_history(hist, HIST_PATH),
				free(prompt.line), ft_free_env(venv), 0);
		cmd = ft_get_cmds(prompt.line);
		if (free(prompt.line), !prompt.to_execute || !cmd)
		{
			ft_free_cmds(cmd);
			continue ;
		}
		if (prompt.to_execute)
			ft_exec_cmds((t_exec_params){0, cmd, cmd, venv, cmd->link_type});
		cmd = (ft_free_cmds(cmd), NULL);
	}
	return (free_lchistory(hist), ft_free_env(venv), 0);
}
