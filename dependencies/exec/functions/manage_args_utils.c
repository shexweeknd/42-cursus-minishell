/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:24:30 by ballain           #+#    #+#             */
/*   Updated: 2024/10/16 16:11:36 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

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
	int		len;
	char	*tmp;
	char	*var;

	var = NULL;
	var = ((tmp = ft_substr(arg, 0, lenv)), ft_getvar(env, tmp));
	if (!var)
		return (free(tmp), 0);
	len = ft_strlcpy(dest, var, ft_strlen(var) + 1);
	return (free(tmp), free(var), len);
}

int	ft_add_status(char *dest)
{
	int	status;
	int	len;
	int	r_len;

	status = get_status();
	len = ft_nblen(status);
	r_len = len;
	while (len)
	{
		*(dest + (--len)) = (status % 10) + '0';
		status /= 10;
	}
	return (r_len);
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
				len += ((*arg += 1), ft_nblen(get_status()));
			else if (!ft_isalpha(**arg) && **arg != '_')
				len++;
			else
				*arg += ((len += ft_lenvar(*arg, env, lenv)), lenv);
		}
		else
			len += ((*arg += 1), 1);
	}
	return (len);
}
