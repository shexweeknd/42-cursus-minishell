/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:55:43 by hramaros          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/12 20:44:39 by ballain          ###   ########.fr       */
=======
/*   Updated: 2024/09/12 20:50:42 by ballain          ###   ########.fr       */
>>>>>>> b1a737c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_prompt	pt;

	((void)argc, (void)argv);
	init_prompt(&pt, envp, HIST_PATH);
	while (1)
	{
		(setup_main_signals(), get_prompt(&pt, MSH_NAME));
		pt.hist = ft_append_hist_elem(pt.hist, ft_strdup(pt.line));
		if (!pt.line || strcmp(pt.line, "exit") == 0 || pt.to_exit)
			return (printf("exit\n"), set_history(pt.hist, HIST_PATH),
				free(pt.line), ft_free_env(pt.venv), 0);
		pt.cmd = ft_get_cmds(pt.line);
		if (free(pt.line), !pt.to_execute || !pt.cmd)
		{
			ft_free_cmds(pt.cmd);
			continue ;
		}
		ft_exec_cmds((t_exec_params){0, pt.cmd, pt.cmd, pt.venv,
			pt.cmd->l_type});
		pt.cmd = (ft_free_cmds(pt.cmd), NULL);
	}
	return (free_lchistory(pt.hist), ft_free_env(pt.venv), 0);
}
