/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:25:38 by ballain           #+#    #+#             */
/*   Updated: 2024/09/04 10:49:30 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_buildin_cmd(t_cmd *cmd, t_env_var *venv)
{
	// if (ft_strcmp(cmd->args[0], "echo") == 0)
	// 	return (echo(cmd), 1);
	if (ft_strcmp(cmd->args[0], "cd") == 0)
		return (cd(cmd), 1);
	if (ft_strcmp(cmd->args[0], "env") == 0)
		return (ft_env(venv), 1);
	if (ft_strcmp(cmd->args[0], "export") == 0)
		return (export(cmd), 1);
	if (ft_strcmp(cmd->args[0], "pwd") == 0)
		return (pwd(cmd), 1);
	if (ft_strcmp(cmd->args[0], "unset") == 0)
		return (unset(cmd), 1);
	if (ft_strcmp(cmd->args[0], "exit") == 0)
		return (ft_exit(), 1);
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
	else if (cmd->next)
		dup2(fd[1], STDOUT_FILENO);
}

void	ft_close_fd(int fd[2], int r_fd[2])
{
	close(fd[0]);
	close(fd[1]);
	if (r_fd[0] != -1)
		close(r_fd[0]);
	if (r_fd[1] != -1)
		close(r_fd[1]);
}

int	ft_exec_cmd(int fd[2], int r_fd[2], t_cmd *cmd, t_env_var *venv)
{
	int		id;
	char	*exe;

	if (!cmd->args)
		return (0);
	ft_manage_redirect_file(fd, r_fd, cmd);
	ft_close_fd(fd, r_fd);
	if (ft_buildin_cmd(cmd, venv))
		return (1);
	exe = ft_search_executable(venv, cmd->args[0]);
	if (!exe)
		return (printf("Minishell: %s: command not found\n", cmd->args[0]), 0);
	free(cmd->args[0]);
	cmd->args[0] = exe;
	id = fork();
	if (id == 0)
		execve(exe, cmd->args, NULL);
	else
		wait(NULL);
	return (1);
}

int	ft_exec_cmds(t_exec_params params)
{
	int		fd[2];
	int		r_fd[2];

	if (!params.cmd)
		return (0);
	r_fd[0] = -1;
	r_fd[1] = -1;
	if (pipe(fd) == -1)
		return (1);
	if (params.link_type == PIPE)
	{
		if (fork() == 0)
		{
			if (params.read_fd != 0)
				(dup2(params.read_fd, STDIN_FILENO), close(params.read_fd));
			(ft_exec_cmd(fd, r_fd, params.cmd, params.venv), exit(0));
		}
	}
	else
		ft_exec_cmd(fd, r_fd, params.cmd, params.venv);
	(close(fd[1]), wait(NULL));
	ft_exec_cmds((t_exec_params) \
			{fd[0], params.cmd->next, params.venv, params.cmd->link_type});
	return (0);
}
