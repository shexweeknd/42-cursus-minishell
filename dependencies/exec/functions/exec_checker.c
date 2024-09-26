/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:28:57 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/26 11:44:24 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

void	p_exec_log(char *msg, char *file_exe)
{
	printf("%s: %s: %s\n", MSH_LOG, msg, file_exe);
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
	p_exec_log("command not found", file_exe);
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