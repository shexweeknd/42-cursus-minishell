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
	int		len_var;

	len = 0;
	while (*arg && *arg != '"')
	{
		len_var = ft_isvar(arg);
		if (len_var)
		{
			tmp = ft_substr(++arg, 0, len_var);
			len += ft_strlen(ft_getvar(env, tmp));
			arg += (free(tmp), tmp = NULL, len_var);
		}
		else
		{
			len++;
			arg++;
		}
	}
	return (len);
}

int	ft_new_len_args(char *arg, t_env *env)
{
	int		len;
	char	quote;
	char	*end_quote;

	len = 0;
	while (arg && *arg)
	{
		quote = ft_is_quote(*arg);
		if (quote && arg++)
		{
			end_quote = ft_strchr((arg), quote);
			if (*end_quote == '"')
				arg = ((len += ft_dqoute_len(arg, env)), ++end_quote);
			else if (*end_quote == '\'')
				arg = ((len += end_quote - arg), ++end_quote);
			else
				len++;
		}
		else
		{
			arg++;
			len++;
		}
	}
	return (len);
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
