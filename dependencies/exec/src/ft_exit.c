/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:43:12 by ballain           #+#    #+#             */
/*   Updated: 2024/09/27 13:44:46 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	valid_exit_args(t_cmd *cmd)
{
	if (!cmd->args[1])
	{
		if (isatty(STDIN_FILENO))
			printf("exit\n");
		return (1);
	}
	if (!ft_isnbr(cmd->args[1]))
	{
		if (isatty(STDIN_FILENO))
			printf("exit\n");
		return (ft_printf_fd("\033[0;32m%s:\033[0;0m exit: %s%s", 2, MSH_LOG,
				cmd->args[1], ": numeric argument required\n"), set_status(2),
			1);
	}
	else if (cmd->args[2])
		return (ft_printf_fd("\033[0;32m%s:\033[0;0m exit: %s", 2, MSH_LOG,
				": too many arguments\n"), set_status(ft_atoi(cmd->args[1])),
			0);
	return (0);
}

void	ft_exit(t_executable exec)
{
	if (!exec.cmd || valid_exit_args(exec.cmd))
	{
		set_history(exec.hist, get_histpath());
		ft_free_env(exec.env);
		ft_free_cmds(exec.cmd);
		if (!exec.cmd)
			printf("exit\n");
		exit(get_status());
		ft_clear_paths();
	}
}
