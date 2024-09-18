/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:17:17 by hramaros          #+#    #+#             */
/*   Updated: 2024/0c9/17 17:29:25 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

// bash: cd: « OLDPWD » non défini

char	*ft_default_path(char *str, char *type)
{
	if (!str)
		return (printf("minishell: cd : « %s » non défini\n", type), NULL);
	return (ft_strdup(str));
}

int	cd(t_executable exec)
{
	char	*old_path;
	// char	*cur_path;
	char	*home_path;
	char	*path;
	char	*error;

	if (ft_getlen_strtab(exec.cmd->args) > 2)
		return (0);
	home_path = ft_getvar(exec.env, "HOME");
	old_path = ft_getvar(exec.env, "OLDPWD");
	// cur_path = ft_getvar(exec.env, "PWD");
	if (home_path && !exec.cmd->args[1])
		path = ft_strdup(home_path);
	else if (home_path && *exec.cmd->args[1] == '~')
		path = ft_default_path(\
			ft_str_replace(exec.cmd->args[1], "~", home_path, 0), "HOME");
	else if (old_path && !ft_strncmp(exec.cmd->args[1], "-", 1))
		path = ft_default_path(old_path, "OLDPWD");
	else
		path = ft_strdup(exec.cmd->args[1]);
	if (path)
	{
		if (chdir(path) == -1)
		{
			error = strerror(errno);
			(printf("%s\n", error), free(error));
		}
		return (free(path), 0);
	}
	return (1);
}
