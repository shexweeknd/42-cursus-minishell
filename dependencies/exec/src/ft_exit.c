/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:43:12 by ballain           #+#    #+#             */
/*   Updated: 2024/10/16 20:32:15 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	valid_exit_args(t_cmd *cmd)
{
	if (isatty(STDIN_FILENO))
		printf("exit\n");
	if (!cmd->args[1])
		return (1);
	if (!ft_isnbr(cmd->args[1]))
		return (ft_perror_fd(2, (char *[]){"\033[0;32m", MSH_LOG,
				":\033[0;0m exit: ", cmd->args[1],
				": numeric argument required", NULL}), set_status(2), 1);
	else if (cmd->args[2])
		return (ft_perror_fd(2, (char *[]){"\033[0;32m", MSH_LOG,
				":\033[0;0m exit: too many arguments", NULL}), set_status(1),
			0);
	if (cmd->args[1] && ft_isnbr(cmd->args[1]))
		set_status(ft_atoi(cmd->args[1]));
	return (1);
}

void	ft_exit(t_executable exec)
{
	if (!exec.cmd || valid_exit_args(exec.cmd))
	{
		if (exec.hist)
			set_history(exec.hist, get_histpath());
		if (exec.env)
			ft_free_env(exec.env);
		if (exec.cmd)
			ft_free_cmds(exec.cmd);
		if (!exec.cmd)
			printf("exit\n");
		ft_clear_paths();
		if (exec.s_fd[0] != -1 && exec.s_fd[1] != -1)
			ft_pipe_status(exec.s_fd, get_status(), 1);
		exit(get_status());
	}
}
