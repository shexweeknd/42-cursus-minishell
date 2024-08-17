/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:15:07 by ballain           #+#    #+#             */
/*   Updated: 2024/08/17 01:16:24 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static void	_free_cmd(void *value, t_list_type type)
{
	t_lst_utils	utils;
	int			i;

	if (!value)
		return ;
	if (type == CMD)
	{
		utils = (t_lst_utils){IO_ARG, _free_cmd, _next_cmd};
		i = 0;
		if (((t_cmd *)value)->args)
		{
			while (((t_cmd *)value)->args[i])
				free(((t_cmd *)value)->args[i++]);
			free(((t_cmd *)value)->args[i]);
			free(((t_cmd *)value)->args);
		}
		if (((t_cmd *)value)->io_arg)
			_loop((void **)&((t_cmd *)value)->io_arg, utils);
	}
	else if (type == IO_ARG)
		free(((t_io_arg *)value)->arg);
	free(value);
}

void	ft_free_cmds(t_cmd *cmd)
{
	_loop((void **)&cmd, (t_lst_utils){CMD, _free_cmd, _next_cmd});
}
