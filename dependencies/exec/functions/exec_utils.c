/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:13:56 by ballain           #+#    #+#             */
/*   Updated: 2024/09/24 15:15:53 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_check_valid_var(char *var, int status)
{
	if (ft_isdigit(*var))
	{
		printf("minishell: export: `%s': not a valid identifier\n", var);
		return (1);
	}
	return (status);
}

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
	pipe(r_value.s_fd);
	r_value.o_fd[0] = dup(STDIN_FILENO);
	r_value.o_fd[1] = dup(STDOUT_FILENO);
	r_value.cmd = param.cmd;
	r_value.env = param.env;
	r_value.hist = param.hist;
	return (r_value);
}

void	ft_free_executable(t_executable exec, t_cmd *cmd)
{
	ft_free_cmds(cmd);
	ft_free_env(exec.env);
	free_lchistory(exec.hist);
}

void	ft_next_cmds(int fd[2], t_exec_params params)
{
	close(fd[1]);
	ft_exec_cmds((t_exec_params){fd[0], params.src, params.cmd->next, \
					params.env, params.hist, params.cmd->l_type});
	wait(NULL);
}

