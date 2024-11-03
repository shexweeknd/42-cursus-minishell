/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:15:07 by ballain           #+#    #+#             */
/*   Updated: 2024/11/03 12:09:47 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	ft_free_args(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd && cmd->args && cmd->args[i])
		free(cmd->args[i++]);
	free(cmd->args[i]);
	free(cmd->args);
}

void	_free_cmd(void *value, int type)
{
	t_lst_utils	utils;

	if (!value)
		return ;
	if (type == CMD)
	{
		utils = (t_lst_utils){R_FILE, _free_cmd, _next_cmd};
		if (((t_cmd *)value)->args)
			ft_free_args((t_cmd *)value);
		if (((t_cmd *)value)->file_in)
			_loop((void **)&((t_cmd *)value)->file_in, utils);
		if (((t_cmd *)value)->file_out)
			_loop((void **)&((t_cmd *)value)->file_out, utils);
	}
	if (type == R_FILE)
		free(((t_rfile *)value)->args);
	free(value);
}

void	ft_free_cmds(t_cmd *cmd)
{
	_loop((void **)&cmd, (t_lst_utils){CMD, _free_cmd, _next_cmd});
}
