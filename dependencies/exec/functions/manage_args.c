#include "ft_exec.h"

int	ft_has_venv(char *arg)
{
	while (*arg)
	{
		if (*arg == '$' && *(arg + 1) != '"' && !ft_isspace(*(arg + 1)))
			return (1);
		arg++;
	}
	return (0);
}

int	ft_dqoute_len(char *arg, t_env *env)
{
	char	*tmp;
	int		len;

	len = 0;
	while (*arg && *tmp != '"')
	{
		if (*arg == '$')
		{
			tmp = ++arg;
			while (*tmp && !ft_isspace(*tmp) && *tmp != '"')
				tmp++;
			if (tmp - arg)
			{
				arg = ft_substr(arg, 0, tmp - arg);
				len += ft_strlen(ft_getvar(env, arg));
				arg = (free(arg), tmp);
			}
			else
				len++;
		}
		else
			(len++, arg++);
	}
	return (len);
}

int	ft_new_len_args(char *arg, t_env *env)
{
	int		len;
	char	quote;
	char	*end_quote;

	(void)env;
	len = 0;
	if (!arg)
		return (len);
	while (*arg)
	{
		quote = ft_is_quote(*arg);
		if (quote)
		{
			end_quote = ft_strchr((arg + 1), quote);
			// if (end_quote && quote ==)
		}
		arg++;
	}
	return (0);
}

void	ft_manage_args(t_cmd *cmd, t_env *env)
{
	int	i;

	i = 0;
	(void)env;
	while (cmd->args[i])
	{
		i++;
	}
}
