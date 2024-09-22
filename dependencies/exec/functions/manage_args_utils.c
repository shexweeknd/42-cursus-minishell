/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:24:30 by ballain           #+#    #+#             */
/*   Updated: 2024/09/22 13:33:41 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_isvar(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	if (*str == '$' && str++)
	{
		if (!*str || *str == '?' || ft_isdigit(*str) || \
			(!ft_isalpha(*str) && *str != '_'))
			return (1);
		while (*str && (ft_isalpha(*str) || *str == '_'))
		{
			str++;
			len++;
		}
		return (len);
	}
	return (0);
}

int	ft_lenvar(char *arg, t_env *env, int lenv)
{
	char	*tmp;
	int		len;

	tmp = ft_substr(arg, 0, lenv);
	len = ft_strlen(ft_getvar(env, tmp));
	tmp = (free(tmp), NULL);
	return (len);
}

int	ft_cpvar(char *dest, char *arg, t_env *env, int lenv)
{
	char	*tmp;
	char	*var;

	var = NULL;
	var = ((tmp = ft_substr(arg, 0, lenv)), ft_getvar(env, tmp));
	if (!var)
		return (0);
	return (free(tmp), ft_strlcpy(dest, var, ft_strlen(var) + 1));
}

int	ft_dqoute_len(char **arg, t_env *env, char *stop)
{
	int		len;
	int		lenv;

	len = 0;
	while (**arg && !ft_strchr(stop, **arg))
	{
		lenv = ft_isvar(*arg);
		if (lenv)
		{
			if ((*arg)++ && (!**arg || \
				(!ft_strcmp(stop, "\"") && ft_strchr(stop, **arg))))
				return ((len += lenv), len);
			if (ft_strchr(stop, **arg))
				return (len);
			if (**arg == '?')
				len += ((*arg += 1), 1);
			else
				*arg += ((len += ft_lenvar(*arg, env, lenv)), lenv);
		}
		else
			len += ((*arg += 1), 1);
	}
	return (len);
}

int	ft_dquote_add(char *dest, char **arg, t_env *env, char *stop)
{
	int		i;
	int		lenv;

	i = 0;
	while (**arg && ft_strchr(stop, **arg) == NULL)
	{
		lenv = ft_isvar(*arg);
		if (lenv)
		{
			(*arg)++;
			if (!**arg || (!ft_strcmp(stop, "\"") && ft_strchr(stop, **arg)))
				return ((dest[i] = '$'), (i += lenv), i);
			else if (ft_strchr(stop, **arg))
				break ;
			else if (**arg == '?')
				dest[i++] = ((*arg += 1), STATUS);
			else
				*arg += ((i += ft_cpvar((dest + i), *arg, env, lenv)), lenv);
		}
		else
			*arg += ((dest[i++] = **arg), 1);
	}
	return (i);
}
