/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:17:49 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/24 15:19:19 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

static int	ft_delvar(t_env *env, char *var_name)
{
	int		i;
	int		j;
	int		len;
	char	**new_env;

	new_env = (char **)malloc(sizeof(char *) * ft_getlen_strtab(env->var));
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
	if (!ft_strcmp(var_name, "PATH"))
		(free(*env->path), free(env->path));
	return (0);
}

int	unset(t_executable exec)
{
	int		i;
	int		status;

	if (!exec.cmd->args[1])
		return (0);
	status = ((i = 0), i);
	while (exec.cmd->args[++i])
	{
		status = ft_check_valid_var(exec.cmd->args[i], status);
		if (ft_search_var(exec.env, exec.cmd->args[i]))
			ft_delvar(exec.env, exec.cmd->args[i]);
	}
	return (status);
}
