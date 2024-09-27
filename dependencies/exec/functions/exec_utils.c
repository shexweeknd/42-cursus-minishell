/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:13:56 by ballain           #+#    #+#             */
/*   Updated: 2024/09/27 11:25:52 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_check_valid_var(char *var, int status)
{
	if (ft_isdigit(*var))
	{
		ft_printf_fd("%s: export: `%s': not a valid identifier\n", 2, MSH_LOG,
			var);
		return (1);
	}
	return (status);
}

char	*ft_search_executable(t_executable exec)
{
	char	*tmp;

	if (!exec.env->path || is_directory(exec.cmd->args[0]))
		return (NULL);
	if (*exec.cmd->args[0] != '/' && ft_strncmp(exec.cmd->args[0], "./", 2)
		&& ft_strncmp(exec.cmd->args[0], "~/", 2))
	{
		tmp = is_exec_from_path(&exec);
		if (tmp == NULL)
			return (cmd_found(exec.cmd->args[0], 1), tmp);
		if (tmp)
			return (tmp);
	}
	else if (*exec.cmd->args[0] == '/' || ft_strncmp(exec.cmd->args[0], "./", 2)
		|| ft_strncmp(exec.cmd->args[0], "~/", 2))
	{
		if (!cmd_found(exec.cmd->args[0], 0)
			|| !cmd_executable(exec.cmd->args[0], 0))
			return (NULL);
	}
	return (exec.cmd->args[0]);
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
	ft_exec_cmds((t_exec_params){fd[0], params.src, params.cmd->next,
		params.env, params.hist, params.cmd->l_type});
	wait(NULL);
}
