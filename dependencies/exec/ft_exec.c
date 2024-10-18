/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:25:38 by ballain           #+#    #+#             */
/*   Updated: 2024/10/18 09:38:27 by ballain          ###   ########.fr       */
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

	status = (ft_manage_args(exec.cmd, exec.env), 0);
	if (!ft_manage_redirect_file(exec.p_fd, exec.cmd))
		return (1);
	if (!exec.cmd->args || !exec.cmd->args[0])
		return (0);
	if (ft_builtin_cmd(exec))
		return (get_status());
	exe = ft_search_executable(exec);
	if (!exe)
		return (get_status());
	if (exe != exec.cmd->args[0])
		exec.cmd->args[0] = (free(exec.cmd->args[0]), exe);
	if (fork() == 0)
	{
		if (signal(SIGINT, SIG_DFL), signal(SIGQUIT, SIG_DFL), execve(exe,
				exec.cmd->args, exec.env->var) == -1)
			(ft_perror_fd(2, (char *[]){strerror(errno), "\n", NULL}),
				exit(EXIT_FAILURE));
	}
	else
		(wait(&status), ft_save_cmd_in_env(exec));
	return (ft_exit_status(status));
}

void	exec_cmds_left(t_exec_params *params, t_executable *exec)
{
	int	status;

	if (params->read_fd != 0)
		(dup2(params->read_fd, STDIN_FILENO), close(params->read_fd));
	status = ft_exec_cmd(*exec);
	if (exec && exec->cmd && exec->cmd->l_type == NONE)
		ft_pipe_status(exec->s_fd, status, 1);
	(ft_free_executable(*exec), exit(get_status()));
}

void	exec_cmds_right(t_exec_params *params, t_executable *exec)
{
	t_link	redirect_type;

	redirect_type = exec->cmd->l_type;
	if (params->read_fd != 0)
		close(params->read_fd);
	ft_next_cmds(exec->p_fd, *params);
	if (redirect_type == NONE)
		set_status(ft_pipe_status(exec->s_fd, 0, 0));
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
			exec_cmds_left(&params, &exec);
		else
			exec_cmds_right(&params, &exec);
	}
	else
	{
		exec.s_fd[0] = ((exec.s_fd[1] = -1), -1);
		if (params.l_type == OR && get_status() != 0)
			ft_exec_cmd(exec);
		else
			set_status(ft_exec_cmd(exec));
		(ft_reset_fd(exec), ft_next_cmds(exec.p_fd, params));
	}
	return (0);
}
