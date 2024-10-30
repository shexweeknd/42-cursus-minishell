/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:28:57 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/30 14:10:06 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	is_directory(const char *path)
{
	DIR	*dir;

	if (is_only_spaces((char *)path) || (ft_strlen(path) == 2
			&& !ft_strncmp(path, "..", 2)))
		return (cmd_found((char *)path, 1), 1);
	dir = opendir(path);
	if (dir)
	{
		ft_perror_fd(2, (char *[]){MSH_LOG, ": ", (char *)path,
			": Is a directory", NULL});
		return (closedir(dir), set_status(126), 1);
	}
	return (0);
}

char	*is_exec_from_path(t_executable *exec)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!exec->env->path)
		return (NULL);
	while (exec->env->path[i])
	{
		tmp = create_subdir(exec, i++);
		if (!tmp)
			return (NULL);
		if (access(tmp, F_OK) == 0)
		{
			if (!cmd_executable(tmp, 0))
				return (free(tmp), NULL);
			return (tmp);
		}
		free(tmp);
	}
	if (ft_get_occ(exec->cmd->args[0], '/'))
		return (process_hard_links(exec));
	return (cmd_found(exec->cmd->args[0], 1), NULL);
}

char	*is_exec_here(t_executable *exec)
{
	char	*cwd;
	char	*tmp;
	char	*result;

	result = NULL;
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (NULL);
	tmp = ft_strjoin(cwd, "/");
	result = ft_strjoin(tmp, exec->cmd->args[0]);
	if (free(tmp), !result)
		return (NULL);
	if (access(result, F_OK) == 0)
	{
		if (!cmd_executable(result, 0))
			return (free(cwd), free(result), NULL);
		return (free(cwd), result);
	}
	return (free(cwd), free(result), NULL);
}

char	*find_exec(t_executable *exec)
{
	char	*result;

	result = NULL;
	result = is_exec_from_path(exec);
	if (!result)
		result = is_exec_here(exec);
	return (result);
}
