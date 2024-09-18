/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:17:11 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/18 21:58:24 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

char	*ft_getvar_name(char *arg)
{
	char	*equal;

	equal = ft_strchr(arg, '=');
	if (equal)
		return (ft_substr(arg, 0, equal - arg));
	return (NULL);
}

char	**ft_new_env(t_env *env, char *new)
{
	int		i;
	char	**r_value;

	i = -1;
	r_value = (char **)malloc(sizeof(char *) * (ft_getlen_strtab(env) + 2));
	if (!r_value)
		return (NULL);
	while (env->var[++i])
		r_value[i] = env->var[i];
	r_value[i++] = new;
	r_value[i] = NULL;
	free(env->var);
	return (r_value);
}

void	export(t_executable exec)
{
	int		i;
	int		len;
	char	*var_name;

	i = -1;
	var_name = ft_getvar_name(exec.cmd->args[1]);
	while (exec.env->var[++i])
	{
		if (ft_strncmp(exec.env->var[i], var_name, len) == 0 && \
			exec.env->var[i][len] == '=')
			break ;
	}
	if (exec.env->var[i])
		exec.env->var[i] = (free(exec.env->var[i]), exec.cmd->args[1]);
	else
	{}
}
