/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:42:58 by ballain           #+#    #+#             */
/*   Updated: 2024/10/16 15:20:36 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_check_valid_var(char *var)
{
	int	i;
	int	has_error;

	has_error = ((i = 0), i);
	if ((var && ft_isdigit(var[i])) || !var || var[i] == '=')
		has_error = (i++, 1);
	if (!var)
		var = "";
	while (var && var[i] && var[i] != '=')
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			has_error = 1;
		i++;
	}
	if (has_error)
	{
		ft_perror_fd(2, (char *[]){MSH_LOG, ": export: `", var, \
			"': not a valid identifier", NULL});
		return (1);
	}
	if (var && var[i] && var[i] == '=')
		var[i] = 0;
	return (0);
}

char	*ft_search_executable(t_executable exec)
{
	exec.cmd->args[0] = subst_home(exec.cmd->args[0], exec.env);
	if ((!exec.cmd || !exec.cmd->args) || is_directory(exec.cmd->args[0])
		|| ((!exec.env || !exec.env->path) && (!cmd_found(exec.cmd->args[0], 0)
				|| !cmd_executable(exec.cmd->args[0], 0))))
		return (NULL);
	else if (*exec.cmd->args[0] != '/' && ft_strncmp(exec.cmd->args[0], "./", 2)
		&& ft_strncmp(exec.cmd->args[0], "~/", 2))
		return (is_exec_from_path(&exec));
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

void	ft_free_executable(t_executable exec)
{
	ft_free_cmds(exec.cmd);
	ft_free_env(exec.env);
	free_lchistory(exec.hist);
	ft_clear_paths();
}

void	ft_next_cmds(int fd[2], t_exec_params params)
{
	t_cmd	*next;
	t_link	l_type;

	next = params.cmd->next;
	l_type = params.cmd->l_type;
	close(fd[1]);
	if (params.l_type == AND && get_status() != 0)
		return ;
	if (params.l_type == OR && get_status() == 0)
		return ;
	if (params.cmd)
		_free_cmd(params.cmd, CMD);
	ft_exec_cmds((t_exec_params){fd[0], next, params.env, params.hist, l_type});
	wait(NULL);
}
