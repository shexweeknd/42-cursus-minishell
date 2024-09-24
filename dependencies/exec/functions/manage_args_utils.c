/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:24:30 by ballain           #+#    #+#             */
/*   Updated: 2024/09/24 15:55:07 by ballain          ###   ########.fr       */
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

int	ft_getlen_status(void)
{
	int	status;
	int	len;

	len = ((status = get_status()), 0);
	if (!status)
		return (1);
	while (status)
		status /= (len++, 10);
	return (len);
}

int	ft_add_status(char *dest)
{
	int	status;
	int	len;
	int	r_len;

	r_len = ((status = get_status()), (len = ft_getlen_status()), len);
	while (len)
	{
		*(dest + (--len)) = (status % 10) + '0';
		status /= 10;
	}
	return (r_len);
}
