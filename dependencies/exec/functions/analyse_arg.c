#include "ft_exec.h"

char	*ft_analyse_arg(char **args, t_env_var *venv)
{
	(void)args;
	(void)venv;
	return (NULL);
}

void	ft_analyse_args(t_cmd *cmd, t_env_var *venv, void (*_do)())
{
	int	i;
	int	id;

	i = 1;
	while (i < cmd->arg_len)
	{
		id = fork();
		if (id == 0)
		{
			_do(&cmd->args[i], venv);
			break ;
		}
		wait(NULL);
		i++;
	}
}
