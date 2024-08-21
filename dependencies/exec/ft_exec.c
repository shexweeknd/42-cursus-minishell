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

int	ft_manage_file(int default_fd, t_list *file, int O_OPTION, int apply_all)
{
	int	fd;

	if (!file)
		return (default_fd);
	while (file->next)
	{
		if (apply_all)
		{
			fd = open((char *)file->content, O_OPTION);
			close(fd);
		}
		file = file->next;
	}
	fd = open((char *)file->content, O_OPTION);
	if (fd == -1)
	{
		perror("ERROR WHEN OPEN FILE\n");
		return (default_fd);
	}
	return (fd);
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
	{
		perror("FILE DOESN'T EXIST...\n");
		exit(1);
	}
	if (pipe(fd) == -1)
	{
		perror("TUNNELING ERROR ...\n");
		exit(1);
	}
	id = fork();
	if (id == 0)
	{
		dup2(desc, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/usr/bin/grep", (char *[]){"/usr/bin/grep", "main", NULL}, envp);
	}
	else
	{
		id = fork();
		if (id == 0)
		{
			dup2(fd[0], STDIN_FILENO);
			dup2(result_id, STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			execve("/usr/bin/cat", (char *[]){"/usr/bin/cat", NULL}, envp);
		}
		else
			wait(NULL);
	}
	return (1);
}
