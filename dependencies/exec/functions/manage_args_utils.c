/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:24:30 by ballain           #+#    #+#             */
/*   Updated: 2024/09/11 16:13:40 by hramaros         ###   ########.fr       */
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
		if (!*str || ft_isdigit(*str) || (!ft_isalpha(*str) && *str != '_'))
			return (0);
		if (*str && *str == '?')
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

int	ft_dqoute_len(char **arg, t_env *env, char *stop)
{
	char	*tmp;
	int		len;
	int		len_var;

	len = 0;
	while (**arg && !ft_strchr(stop, **arg))
	{
		len_var = ft_isvar(*arg);
		if (len_var)
		{
			*arg += 1;
			tmp = ft_substr(*arg, 0, len_var);
			len += ft_strlen(ft_getvar(env, tmp));
			*arg += (free(tmp), tmp = NULL, len_var);
		}
		else
		{
			len++;
			*arg += 1;
		}
	}
	return (len);
}

int	ft_dquote_add(char *dest, char **arg, t_env *env, char *stop)
{
	char	*tmp;
	char	*var;
	int		i;
	int		len_var;

	i = 0;
	while (**arg && !ft_strchr(stop, **arg))
	{
		len_var = ft_isvar(*arg);
		if (len_var)
		{
			*arg += 1;
			tmp = ft_substr(*arg, 0, len_var);
			var = ft_getvar(env, tmp);
			while (var && *var)
				dest[i++] = *(var++);
			*arg += (free(tmp), tmp = NULL, len_var);
		}
		else
		{
			dest[i++] = **arg;
			*arg += 1;
		}
	}
	return (i);
}
