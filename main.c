/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:55:43 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/27 12:22:45 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_prompt	pt;

	((void)argc, (void)argv, (void)envp);
	ft_init_paths(getenv("PWD"));
	init_prompt(&pt, envp, get_histpath());
	while (1)
	{
		(setup_main_signals(), get_prompt(&pt, MSH_PROMPT));
		pt.hist = ft_append_hist_elem(pt.hist, ft_strdup(pt.line));
		if (pt.to_exit)
			return (exit(get_status()), 0);
		if (!pt.to_execute && (free(pt.line), 1))
			continue ;
		pt.cmd = ft_get_cmds(pt.line);
		if ((free(pt.line), 1) && !pt.cmd)
			continue ;
		ft_manage_args(pt.cmd, pt.venv);
		ft_exec_cmds((t_exec_params){0, pt.cmd, pt.cmd, pt.venv, pt.hist,
			pt.cmd->l_type});
		sec_prompt_flag('r', 0);
		pt.cmd = (ft_free_cmds(pt.cmd), NULL);
	}
	return (free_lchistory(pt.hist), ft_free_env(pt.venv), 0);
}
