#include "ft_exec.h"

void	ft_analyse_arg(char **arg, t_env_var *venv)
{
	char	*tmp;

	if (!arg && !*arg && !**arg)
		return ;
	if (**arg && **arg == '\'')
	{
		tmp = ft_strtrim(*arg, "'");
		free(*arg);
		*arg = tmp;
	}
	if (**arg && **arg == '"')
	{
		tmp = ft_strtrim(*arg, "\"");
		free(*arg);
		*arg = ft_init_new_arg(tmp, venv, ft_new_arg_len(tmp, venv));
		free(tmp);
	}
}

void	ft_analyse_args(t_cmd *cmd, t_env_var *venv, void (*_do)())
{
	int	i;
	int	id;

	i = 1;
	while (i < cmd->nb_arg)
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
