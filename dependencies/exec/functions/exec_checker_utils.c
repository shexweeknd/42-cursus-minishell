/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_checker_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:31:42 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/24 13:21:07 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

char	*subst_home(char *src, t_env *env)
{
	char	*tmp;
	char	*result;
	char	*home;

	if (!*src || *src != '~')
		return (src);
	if (!src[1])
		return (free(src), ft_strdup(ft_getvar(env, "HOME")));
	else if (src[1] != '/')
		return (src);
	home = ft_getvar(env, "HOME");
	tmp = ft_substr(src, 1, ft_strlen(src));
	result = ft_strjoin(home, tmp);
	return (free(tmp), result);
}

int	ft_save_cmd_in_env(t_executable exec)
{
	char	*new_cmd;

	new_cmd = ft_strjoin("_=", exec.cmd->args[0]);
	ft_setvar(exec.env, "_", new_cmd);
	free(new_cmd);
	return (0);
}

char	*create_subdir(t_executable *exec, int i)
{
	return (ft_join((char *[]){exec->env->path[i], "/", exec->cmd->args[0],
			NULL}));
}

char	*process_hard_links(t_executable *exec)
{
	if (access(exec->cmd->args[0], F_OK) == 0
		&& cmd_executable(exec->cmd->args[0], 0))
		return (exec->cmd->args[0]);
	return (cmd_found(exec->cmd->args[0], 0), NULL);
}
