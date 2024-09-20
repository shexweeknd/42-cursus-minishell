/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:17:49 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/19 13:19:34 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

static void	ft_delvar(t_env *env, char *var_name)
{
	int		i;
	int		j;
	int		len;
	char	**new_env;

	new_env = (char **)malloc(sizeof(char *) * ft_getlen_strtab(env));
	if (!new_env)
		return (1);
	i = -1;
	j = 0;
	len = ft_strlen(var_name);
	while (env->var[++i])
	{
		if (ft_strncmp(env->var[i], var_name, len) == 0 && \
			env->var[i][len] == '=')
			free(env->var[i]);
		else
			new_env[j++] = env->var[i];
	}
	new_env[j] = 0;
	env->var = (free(env->var), new_env);
}

int	unset(t_executable exec)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;
	char	**new_env;

	if (!exec.cmd->args[1])
		return (0);
	tmp = ft_search_var(exec.env, exec.cmd->args[1]);
	if (tmp)
	{
		
	}
	return (0);
}
