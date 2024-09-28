/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:28:57 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/28 14:03:31 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

void	p_exec_log(char *msg, char *file_exe)
{
	ft_perror_fd(2, (char *[]){MSH_LOG, ": ", file_exe, ": ", msg, NULL});
}

int	cmd_found(char *file_exe, int simulate)
{
	if (simulate)
	{
		p_exec_log("command not found", file_exe);
		return (set_status(127), 0);
	}
	if (access(file_exe, F_OK) == 0)
		return (1);
	p_exec_log("No such file or directory", file_exe);
	return (set_status(127), 0);
}

int	cmd_executable(char *file_exe, int simulate)
{
	if (simulate)
	{
		p_exec_log("Permission denied", file_exe);
		return (set_status(126), 0);
	}
	if (access(file_exe, X_OK) == 0)
		return (1);
	p_exec_log("Permission denied", file_exe);
	return (set_status(126), 0);
}

int	is_directory(const char *path)
{
	DIR	*dir;

	if (is_only_spaces((char *)path))
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
	while (exec->env->path[i])
	{
		tmp = ft_join((char *[]){exec->env->path[i++], "/", exec->cmd->args[0],
				NULL});
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
	return (NULL);
}
