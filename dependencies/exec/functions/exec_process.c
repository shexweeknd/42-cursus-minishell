/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:22:02 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/30 13:04:09 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

void	ft_execve(t_executable exec)
{
	if (signal(SIGINT, SIG_DFL), signal(SIGQUIT, SIG_DFL), \
		execve(exec.cmd->args[0], exec.cmd->args, exec.env->var) == -1)
		(ft_perror_fd(2, (char *[]){strerror(errno), "\n", NULL}),
			exit(EXIT_FAILURE));
}

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

int	ft_is_ambiguous(char *var_name)
{
	if (var_name && *var_name == '$' \
	&& *(var_name + 1) && !getvar(var_name + 1))
	{
		ft_perror_fd(2, (char *[]){MSH_LOG, ": ", \
		var_name, ": ambiguous redirect", NULL});
		return (1);
	}
	return (0);
}

int	ft_manage_rfile(t_rfile *file, t_env *env)
{
	while (file)
	{
		if (ft_is_ambiguous(file->args))
			return (0);
		file = ((ft_manage_arg(&file->args, env)), file->next);
	}
	return (1);
}
