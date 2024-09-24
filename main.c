/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:55:43 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/24 14:14:10 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_prompt	pt;

	((void)argc, (void)argv, (void)envp);
	set_rootpath(ft_strjoin(getenv("PWD"), HIST_PATH));
	init_prompt(&pt, envp, get_rootpath());
	while (1)
	{
		(setup_main_signals(), get_prompt(&pt, MSH_NAME));
		pt.hist = ft_append_hist_elem(pt.hist, ft_strdup(pt.line));
		if (is_exit(pt.line) || pt.to_exit)
			return (exit_msh(&pt), 0);
		pt.cmd = ft_get_cmds(pt.line);
		if (free(pt.line), !pt.to_execute || !pt.cmd)
		{
			ft_free_cmds(pt.cmd);
			continue ;
		}
		ft_manage_args(pt.cmd, pt.venv);
		ft_exec_cmds((t_exec_params){0, pt.cmd, pt.cmd, pt.venv, pt.hist,
			pt.cmd->l_type});
		sec_prompt_flag('r', 0);
		pt.cmd = (ft_free_cmds(pt.cmd), NULL);
	}
	free(get_rootpath());
	return (free_lchistory(pt.hist), ft_free_env(pt.venv), 0);
}
