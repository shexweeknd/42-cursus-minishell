/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:24:30 by ballain           #+#    #+#             */
/*   Updated: 2024/10/07 14:30:48 by ballain          ###   ########.fr       */
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
	char	*tmp;
	char	*var;

	var = NULL;
	var = ((tmp = ft_substr(arg, 0, lenv)), ft_getvar(env, tmp));
	if (!var)
		return (0);
	return (free(tmp), ft_strlcpy(dest, var, ft_strlen(var) + 1));
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

char	**ft_filter_args(char **args)
{
	int		i;
	int		j;
	int		len;
	char	**new_args;

	i = ((len = 0), -1);
	while (args[++i])
	{
		if (ft_strlen(args[i]))
			len++;
	}
	if (i == len)
		return (args);
	i = ((j = 0), -1);
	new_args = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_args)
		return (NULL);
	while (args[++i])
	{
		if (ft_strlen(args[i]))
			new_args[j++] = args[i];
		else
			args[i] = (free(args[i]), NULL);
	}
	return ((new_args[j] = 0), free(args), new_args);
}
