#include "ft_exec.h"

int	_skip_venv(char *arg)
{
	int	len;

	len = 0;
	while (*arg && (ft_isalpha(*arg) || *arg == '_') && arg++)
		len++;
	return (len);
}

int	ft_getlen_venv(char *arg, t_env_var *venv)
{
	int			len;
	char		*var_name;
	t_env_var	*found_var;

	len = _skip_venv(arg);
	if (len == 0)
		return (1);
	var_name = ft_substr(arg, 0, len);
	found_var = ft_get_env_var(venv, var_name);
	free(var_name);
	if (!found_var)
		return (0);
	len = ft_lst_content_len(found_var->content);
	len += ft_lstsize(found_var->content) - 1;
	return (len);
}

int	ft_new_arg_len(char *arg, t_env_var *venv)
{
	int			len;
	char		*tmp;

	len = 0;
	while (*arg)
	{
		tmp = ft_strchr(arg, '$');
		if (!tmp && arg++)
			len++;
		else
		{
			len += (tmp++) - arg;
			arg = tmp;
			len += ft_getlen_venv(arg, venv);
			arg += _skip_venv(arg);
		}
	}
	return (len);
}

int	ft_ltos(char *dest, t_list *src, char sep)
{
	int	i;
	int	j;

	i = 0;
	while (src)
	{
		j = 0;
		while (((char *)src->content)[j])
			dest[i++] = ((char *)src->content)[j++];
		if (src->next && ft_isprint(sep))
			dest[i++] = sep;
		src = src->next;
	}
	return (i);
}

int	ft_manage_venv(char *dest, char *src, t_env_var *venv, int len)
{
	int			i;
	char		*tmp;
	t_env_var	*tmp_v;

	i = 0;
	if (len == 0)
		*(dest + i++) = '$';
	else
	{
		tmp = ft_substr(src, 0, len);
		tmp_v = ft_get_env_var(venv, tmp);
		if (tmp_v)
			i += ft_ltos((dest + i), tmp_v->content, ':');
		free(tmp);
	}
	return (i);
}

char	*ft_init_new_arg(char *arg, t_env_var *venv, int len)
{
	int			i;
	char		*r_value;

	i = 0;
	r_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!r_value)
		return (NULL);
	while (*arg)
	{
		while (*arg && *arg != '$')
			r_value[i++] = *(arg++);
		if (*arg && *arg == '$' && arg++)
		{
			len = _skip_venv(arg);
			i += ft_manage_venv(r_value + i, arg, venv, len);
			arg += len;
		}
	}
	r_value[i] = 0;
	return (r_value);
}

char	*ft_new_arg(char *arg, t_env_var *venv)
{
	char	*tmp;

	if (*arg && *arg == '\'')
		return (ft_strtrim(arg, "'"));
	if (*arg && *arg == '"')
	{
		arg = ft_strtrim(arg, "\"");
		tmp = ft_init_new_arg(arg, venv, ft_new_arg_len(arg, venv));
		free(arg);
		return (tmp);
	}
	return (arg);
}

int	ft_variable(char *arg, t_list *content)
{
	(void)arg;
	(void)content;
	return (0);
}
