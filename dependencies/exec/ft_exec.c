/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:25:38 by ballain           #+#    #+#             */
/*   Updated: 2024/09/17 14:42:16 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_builtin_cmd(t_executable exec)
{
	if (ft_strcmp(exec.cmd->args[0], "echo") == 0)
		return (echo(exec), 1);
	if (ft_strcmp(exec.cmd->args[0], "cd") == 0)
		return (cd(exec), 1);
	if (ft_strcmp(exec.cmd->args[0], "env") == 0)
		return (ft_env(exec), 1);
	if (ft_strcmp(exec.cmd->args[0], "export") == 0)
		return (export(exec), 1);
	if (ft_strcmp(exec.cmd->args[0], "pwd") == 0)
		return (pwd(exec), 1);
	if (ft_strcmp(exec.cmd->args[0], "unset") == 0)
		return (unset(exec), 1);
	if (ft_strcmp(exec.cmd->args[0], "exit") == 0)
		return (ft_exit(exec), 1);
	return (0);
}

void	ft_manage_redirect_file(int fd[2], int r_fd[2], t_cmd *cmd)
{
	t_rfile	*tmp_in;
	t_rfile	*tmp_out;

	tmp_in = cmd->file_in;
	while (tmp_in && tmp_in->next)
		tmp_in = tmp_in->next;
	tmp_out = cmd->file_out;
	while (tmp_out && tmp_out->next)
	{
		close(open(tmp_out->args, tmp_out->option));
		tmp_out = tmp_out->next;
	}
	if (tmp_in)
		r_fd[0] = open(tmp_in->args, tmp_in->option);
	if (tmp_out)
		r_fd[1] = open(tmp_out->args, tmp_out->option);
	if (r_fd[0] != -1 || r_fd[1] != -1)
	{
		if (r_fd[0] != -1)
			dup2(r_fd[0], STDIN_FILENO);
		if (r_fd[1] != -1)
			dup2(r_fd[1], STDOUT_FILENO);
	}
	else if (cmd->next && cmd->l_type == PIPE)
		dup2(fd[1], STDOUT_FILENO);
}

void	ft_close_fd(t_executable exec)
{
	close(exec.p_fd[0]);
	close(exec.p_fd[1]);
	if (exec.r_fd[0] != -1)
		close(exec.r_fd[0]);
	if (exec.r_fd[1] != -1)
		close(exec.r_fd[1]);
}

int	ft_exec_cmd(t_executable exec)
{
	char	*exe;

	if (!exec.cmd->args)
		return (0);
	ft_manage_redirect_file(exec.p_fd, exec.r_fd, exec.cmd);
	ft_close_fd(exec);
	if (!exec.cmd->args[0])
		return (1);
	if (ft_builtin_cmd(exec))
		return (1);
	exe = ft_search_executable(exec);
	if (!exe)
		return (printf("Minishell: %s: command not found\n", exec.cmd->args[0]), 0);
	if (exe != exec.cmd->args[0])
	{
		free(exec.cmd->args[0]);
		exec.cmd->args[0] = exe;
	}
	if (fork() == 0)
		execve(exe, exec.cmd->args, exec.env->var);
	else
		wait(NULL);
	return (1);
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
			(ft_exec_cmd(exec), ft_free_cmds(params.src), ft_free_env(params.env), exit(0));
		}
		else
		{
			close(exec.p_fd[1]);
			if (params.read_fd != 0)
				close(params.read_fd);
			ft_exec_cmds((t_exec_params){exec.p_fd[0], params.src, params.cmd->next,
				params.env, params.hist, params.cmd->l_type});
			wait(NULL);
		}
	}
	else
	{
		(ft_exec_cmd(exec), ft_reset_fd(exec), close(exec.p_fd[1]));
		ft_exec_cmds((t_exec_params){exec.p_fd[0], params.src, params.cmd->next,
				params.env, params.hist, params.cmd->l_type});
	}
	return (wait(NULL), 0);
}
