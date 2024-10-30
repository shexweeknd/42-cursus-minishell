#include "ft_exec.h"

int	ft_new_arg_len(char *arg)
{
	int		len;
	int		len_var;
	char	*tmp;

	len = 0;
	while (arg && *arg)
	{
		len_var = ft_isvar(arg);
		if (len_var && arg++ && (ft_isalpha(*arg) || *arg == '_'))
		{
			if (*arg == '?')
				len += ft_nblen(get_status());
			else
			{
				tmp = ft_substr(arg, 0, len_var);
				printf("VARIABLE	: [%s] [%s]\n", tmp, getvar(tmp));
				len += getvarlen(tmp);
				tmp = (free(tmp), NULL);
			}
			arg += len_var;
		}
		else
			arg += ((len += 1), 1);
	}
	return (len);
}

int	ft_fill_var(char *dest, char *arg, int len_var)
{
	int		i;
	char	*tmp;

	i = 0;
	if (*arg == '?')
		i += ft_add_status(dest + i);
	else if ((!*arg || (!ft_isalnum(*arg) && *arg != '_' && *arg != '$')))
		dest[i++] = '$';
	else
	{
		tmp = ft_substr(arg, 0, len_var);
		i += ft_strlcpy(dest + i, getvar(tmp), getvarlen(tmp) + 1);
		tmp = (free(tmp), NULL);
	}
	return (i);
}

char	*ft_transform_args(char *arg)
{
	int		i;
	size_t	len;
	int		len_var;
	char	*r_value;

	i = 0;
	len = ft_new_arg_len(arg);
	if (len == ft_strlen(arg))
		return (arg);
	r_value = ft_calloc(len + 2, sizeof(char));
	if (!r_value)
		return (NULL);
	while (arg && *arg)
	{
		len_var = ft_isvar(arg);
		if (len_var && arg++)
		{
			i += ft_fill_var(r_value + i, arg, len_var);
			arg += len_var;
		}
		else
			arg += ((r_value[i++] += *arg), 1);
	}
	printf("last index	: [%d]\n", i);
	return (r_value);
}
