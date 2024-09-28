/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:15:07 by ballain           #+#    #+#             */
/*   Updated: 2024/09/28 09:54:08 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	_free_cmd(void *value, int type)
{
	int			i;
	t_lst_utils	utils;

	if (!value)
		return ;
	if (type == CMD)
	{
		i = 0;
		utils = (t_lst_utils){R_FILE, _free_cmd, _next_cmd};
		if (((t_cmd *)value)->args)
		{
			while (((t_cmd *)value)->args[i])
				free(((t_cmd *)value)->args[i++]);
			free(((t_cmd *)value)->args[i]);
			free(((t_cmd *)value)->args);
		}
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
