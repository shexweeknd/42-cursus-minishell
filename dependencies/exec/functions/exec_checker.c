/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:28:57 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/16 08:30:46 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	cmd_found(char *file_exe, int simulate)
{
	if (simulate)
	{
		ft_perror_fd(2, (char *[]){MSH_LOG, ": ", file_exe, ": ",
			"command not found", NULL});
		return (set_status(127), 0);
	}
	if (access(file_exe, F_OK) == 0)
		return (1);
	ft_perror_fd(2, (char *[]){MSH_LOG, ": ", file_exe, ": ",
		"No such file or directory", NULL});
	return (set_status(127), 0);
}

int	cmd_executable(char *file_exe, int simulate)
{
	if (simulate)
	{
		ft_perror_fd(2, (char *[]){MSH_LOG, ": ", file_exe, ": ",
			"Permission denied", NULL});
		return (set_status(126), 0);
	}
	if (access(file_exe, X_OK) == 0)
		return (1);
	ft_perror_fd(2, (char *[]){MSH_LOG, ": ", file_exe, ": ",
		"Permission denied", NULL});
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

char	*create_subdir(t_executable *exec, int i)
{
	return (ft_join((char *[]){exec->env->path[i], "/", exec->cmd->args[0],
			NULL}));
}

char	*is_exec_from_path(t_executable *exec)
{
	int		i;
	char	*tmp;

	i = 0;
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
	{
		if (access(exec->cmd->args[0], F_OK) == 0
			&& cmd_executable(exec->cmd->args[0], 0))
			return (exec->cmd->args[0]);
		return (cmd_found(exec->cmd->args[0], 0), NULL);
	}
	return (cmd_found(exec->cmd->args[0], 1), NULL);
}
