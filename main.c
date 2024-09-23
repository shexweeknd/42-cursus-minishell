/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:55:43 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/23 13:42:04 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_prompt	pt;

	((void)argc, (void)argv, (void)envp);
	init_prompt(&pt, envp, HIST_PATH);
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
	return (free_lchistory(pt.hist), ft_free_env(pt.venv), 0);
}
