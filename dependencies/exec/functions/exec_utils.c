/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:13:56 by ballain           #+#    #+#             */
/*   Updated: 2024/09/16 19:52:24 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

char	*ft_join_path(char *path, char *sep, char *name)
{
	int		i;
	int		len;
	char	*r_value;

	if (!path)
		path = ".";
	if (!sep)
		sep = "/";
	if (!name)
		return (NULL);
	i = 0;
	len = ft_strlen(path) + ft_strlen(path) + ft_strlen(path) + 1;
	r_value = (char *)malloc(sizeof(char) * len);
	if (!r_value)
		return (NULL);
	while (*path)
		r_value[i++] = *(path++);
	while (*sep)
		r_value[i++] = *(sep++);
	while (*name)
		r_value[i++] = *(name++);
	r_value[i] = '\0';
	return (r_value);
}

char	*ft_search_executable(t_executable exec)
{
	char	*tmp;
	int		i;

	i = 0;
	if (access(exec.cmd->args[0], F_OK | X_OK) == 0)
	{
		if (ft_strncmp(exec.cmd->args[0], "./", 2) == 0)
			return (exec.cmd->args[0]);
		return (NULL);
	}
	if (!exec.env->path)
		return (NULL);
	while (exec.env->path[i])
	{
		tmp = ft_join_path(exec.env->path[i++], "/", exec.cmd->args[0]);
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
	return (r_value);
}

void	ft_reset_fd(t_executable exec)
{
	dup2(exec.o_fd[0], STDIN_FILENO);
	dup2(exec.o_fd[1], STDOUT_FILENO);
}
