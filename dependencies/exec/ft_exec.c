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


int	ft_exec_cmd(t_cmd *cmd, t_env_var *venv, char **env)
{
	char	*exe;
	int		id;

	if (!cmd->args)
		return (0);
	exe = ft_search_executable(venv, cmd->args[0]);
	if (!exe && ft_local_exe(cmd))
		return (0);
	free(cmd->args[0]);
	cmd->args[0] = exe;
	id = fork();
	if (id == 0)
		execve(exe, cmd->args, env);
	else
		wait(NULL);
	return (1);
}
