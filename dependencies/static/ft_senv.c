/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_senv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:59:17 by ballain           #+#    #+#             */
/*   Updated: 2024/10/07 14:50:14 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_static.h"

static t_env	*initsenv(t_env *env)
{
	static t_env	*senv;

	if (env)
		senv = env;
	return (senv);
}

t_env	*getsenv(void)
{
	return (initsenv(NULL));
}

void	setsenv(t_env *env)
{
	initsenv(env);
}

static char	*search_var(t_env *env, char *var_name)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(var_name);
	while (env->var[++i])
	{
		if (ft_strncmp(env->var[i], var_name, len) == 0
			&& env->var[i][len] == '=')
			break ;
	}
	return (env->var[i]);
}

char	*getvar(char *var_name)
{
	int		i;
	char	*var;

	i = 0;
	var = search_var(getsenv(), var_name);
	if (var)
	{
		while (var[i++] != '=')
			;
		if (*(var + i))
			return (var + i);
	}
	return (NULL);
}
