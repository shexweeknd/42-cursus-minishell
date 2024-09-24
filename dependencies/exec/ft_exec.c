/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:25:38 by ballain           #+#    #+#             */
/*   Updated: 2024/09/24 16:01:05 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_builtin_cmd(t_executable exec)
{
	if (ft_strcmp(exec.cmd->args[0], "echo") == 0)
		return (set_status(echo(exec)), 1);
	if (ft_strcmp(exec.cmd->args[0], "cd") == 0)
		return (set_status(cd(exec)), 1);
	if (ft_strcmp(exec.cmd->args[0], "env") == 0)
		return (set_status(ft_env(exec)), 1);
	if (ft_strcmp(exec.cmd->args[0], "export") == 0)
		return (set_status(export(exec)), 1);
	if (ft_strcmp(exec.cmd->args[0], "pwd") == 0)
		return (set_status(pwd(exec)), 1);
	if (ft_strcmp(exec.cmd->args[0], "unset") == 0)
		return (set_status(unset(exec)), 1);
	if (ft_strcmp(exec.cmd->args[0], "exit") == 0)
		return (ft_exit(exec), 1);
	return (0);
}

int	ft_exec_cmd(t_executable exec)
{
	char	*exe;
	int		status;

	status = 0;
	if (!exec.cmd->args)
		return (0);
	ft_manage_redirect_file(exec.p_fd, exec.cmd);
	if (!exec.cmd->args[0])
		return (0);
	if (ft_builtin_cmd(exec))
		return (get_status());
	exe = ft_search_executable(exec);
	if (!exe)
		return (printf("Minishell: %s: command not found\n", exec.cmd->args[0]), 127);
	if (exe != exec.cmd->args[0])
		exec.cmd->args[0] = (free(exec.cmd->args[0]), exe);
	if (fork() == 0)
	{
		if (execve(exe, exec.cmd->args, exec.env->var) == -1)
			(printf("%s\n", strerror(errno)), exit(EXIT_FAILURE));
	}
	else
		(wait(&status), ft_print_status(status));
	return (status);
}

int	ft_exec_cmds(t_exec_params params)
{
	t_executable	exec;

	if (!params.cmd)
		return (0);
	exec = ft_init_executable(params);
	if (setup_child_signals(), params.l_type == PIPE)
	{
		if (fork() == 0)
		{
			if (params.read_fd != 0)
				(dup2(params.read_fd, STDIN_FILENO), close(params.read_fd));
			ft_pipe_status(exec.s_fd, ft_exec_cmd(exec), 1);
			(ft_free_executable(exec, params.src), exit(0));
		}
		else
		{
			if (params.read_fd != 0)
				close(params.read_fd);
			set_status(ft_pipe_status(exec.s_fd, 0, 0));
			ft_next_cmds(exec.p_fd, params);
		}
	}
	else
		(set_status(ft_exec_cmd(exec)), ft_reset_fd(exec), ft_next_cmds(exec.p_fd, params));
	return (0);
}
