#include "ft_exec.h"

int	ft_local_exe(t_cmd *cmd)
{
	if (ft_strcmp(cmd->args[0], "echo"))
		echo(cmd);
	if (ft_strcmp(cmd->args[0], "cd"))
		cd(cmd);
	if (ft_strcmp(cmd->args[0], "env"))
		env(cmd);
	if (ft_strcmp(cmd->args[0], "export"))
		export(cmd);
	if (ft_strcmp(cmd->args[0], "pwd"))
		pwd(cmd);
	if (ft_strcmp(cmd->args[0], "unset"))
		unset(cmd);
	if (ft_strcmp(cmd->args[0], "exit"))
		ft_exit(cmd);
	return (0);
}

void	ft_manage_redirect_file(int fd[2], int r_fd[2], t_cmd *cmd)
{
	t_rfile	*tmp_in;
	t_rfile	*tmp_out;
	int		i;

	i = 2;
	
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
	if (cmd->next)
		dup2(fd[1], STDOUT_FILENO);
	if (r_fd[0] != -1)
		dup2(r_fd[0], STDIN_FILENO);
	if (r_fd[1] != -1)
		dup2(r_fd[1], STDOUT_FILENO);
}

int	ft_exec_cmd(t_cmd *cmd, t_env_var *venv, char **env)
{
	char	*exe;

	if (!cmd->args)
		return (0);
	exe = ft_search_executable(venv, cmd->args[0]);
	if (!exe && ft_local_exe(cmd))
		return (0);
	free(cmd->args[0]);
	cmd->args[0] = exe;
	execve(exe, cmd->args, env);
	return (1);
}

int	ft_multi_pipe(t_cmd *cmd, t_env_var *venv, char **envp)
{
	int	i;
	int id;
	int fd[2];
	int r_fd[2];

	i = 2;
	while (i)
		r_fd[--i] = -1;
	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == 0)
	{
		ft_manage_redirect_file(fd, r_fd, cmd); (close(fd[0]), close(fd[1]), ft_exec_cmd(cmd, venv, envp));
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		(close(fd[0]), close(fd[1]));
		if (cmd->next)
			ft_multi_pipe(cmd->next, venv, envp);
		return (wait(NULL), 0);
	}
	return (1);
}

int	ft_exec_cmds(t_cmd *cmd, t_env_var *venv, char **envp)
{
	int	fd[2];
	int	id;
	int	desc;
	int	result_id;

	(void)cmd;
	(void)venv;
	desc = open("tmp.txt", O_RDWR);
	result_id = open("result.txt", O_RDWR);
	if (desc == -1 && result_id == -1)
		return (1);
	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == 0)
	{
		// dup2(desc, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/usr/bin/grep", (char *[]){"/usr/bin/grep", "main", "main.c", NULL}, envp);
	}
	else
	{
		id = fork();
		if (id == 0)
		{
			dup2(fd[0], STDIN_FILENO);
			// dup2(result_id, STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			execve("/usr/bin/cat", (char *[]){"/usr/bin/cat", NULL}, envp);
		}
		else
			wait(NULL);
	}
	return (1);
}
