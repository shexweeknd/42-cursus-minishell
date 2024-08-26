#include "ft_exec.h"

int	ft_getlen_venv(char *arg)
{
	int	len;

	len = 0;
	while (*arg && (ft_isalpha(*arg) || *arg == '_') && arg++)
		len++;
	return (len);
}

int	ft_new_arg_len(char *arg, t_env_var *venv)
{
	int			end;
	int			len;
	int			r_len;
	char		*tmp;
	t_env_var	*t_v;

	end = 0;
	len = 0;
	r_len = 0;
	if (*arg == '"' && arg++)
		end = '"';
	while (*arg && *arg != end)
	{
		tmp = ft_strchr(arg, '$');
		if (!tmp && arg++)
			r_len++;
		else
		{
			r_len += tmp - arg;
			arg = ++tmp;
			len = ft_getlen_venv(arg);
			arg += len;
			tmp = ft_substr(arg, 0, len);
			t_v = ft_get_env_var(venv, tmp);
			r_len += ft_lst_content_len(t_v->content) + (ft_lstsize(t_v->content) - 1);
		}
	}
	return (r_len);
}

int	_skip_venv(char *arg)
{
	(void)arg;
	return (0);
}

int	ft_variable(char *arg, t_list *content)
{
	(void)arg;
	(void)content;
	return (0);
}
