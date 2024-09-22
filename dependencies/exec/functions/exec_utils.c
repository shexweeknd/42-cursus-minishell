/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:13:56 by ballain           #+#    #+#             */
/*   Updated: 2024/09/22 13:39:13 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

char	*ft_search_executable(t_executable exec)
{
	int		i;
	char	*tmp;

	i = 0;
	if (access(exec.cmd->args[0], F_OK | X_OK) == 0)
	{
		if (*exec.cmd->args[0] == '/' || \
			ft_strncmp(exec.cmd->args[0], "./", 2) == 0)
			return (exec.cmd->args[0]);
		return (NULL);
	}
	if (!exec.env->path)
		return (NULL);
	while (exec.env->path[i])
	{
		tmp = ft_join(\
			(char *[]){exec.env->path[i++], "/", exec.cmd->args[0], NULL});
		if (!tmp)
			return (NULL);
		if (access(tmp, F_OK | X_OK) == 0)
			return (tmp);
		free(tmp);
	}
	return (NULL);
}

t_executable	ft_init_executable(t_exec_params param)
{
	t_executable	r_value;

	pipe(r_value.p_fd);
	r_value.r_fd[0] = -1;
	r_value.r_fd[1] = -1;
	r_value.o_fd[0] = dup(STDIN_FILENO);
	r_value.o_fd[1] = dup(STDOUT_FILENO);
	r_value.cmd = param.cmd;
	r_value.env = param.env;
	r_value.hist = param.hist;
	return (r_value);
}

void	ft_free_executable(t_executable exec)
{
	ft_free_cmds(exec.cmd);
	ft_free_env(exec.env);
	free_lchistory(exec.hist);
}

void	ft_reset_fd(t_executable exec)
{
	dup2(exec.o_fd[0], STDIN_FILENO);
	dup2(exec.o_fd[1], STDOUT_FILENO);
}
