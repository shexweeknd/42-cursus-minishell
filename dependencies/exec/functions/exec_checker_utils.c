/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_checker_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:31:42 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/07 14:55:01 by ballain          ###   ########.fr       */
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
