/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:15:07 by ballain           #+#    #+#             */
/*   Updated: 2024/08/15 13:15:07 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	_free(void *value, t_list_type type)
{
	t_lst_utils	utils;

	if (!value)
		return ;
	if (type == CMD)
	{
		utils = (t_lst_utils){IO_ARG, _free, _next};
		ft_show_cmd((t_cmd *)value);
		if (((t_cmd *)value)->name)
			free(((t_cmd *)value)->name);
		if (((t_cmd *)value)->option)
			free(((t_cmd *)value)->option);
		if (((t_cmd *)value)->arg)
			free(((t_cmd *)value)->arg);
		if (((t_cmd *)value)->io_arg)
			_loop((void **)&((t_cmd *)value)->io_arg, utils);
	}
	else if (type == IO_ARG)
		free(((t_io_arg *)value)->arg);
	free(value);
}

void	ft_free_cmds(t_cmd *cmd)
{
	_loop((void **)&cmd, (t_lst_utils){CMD, _free, _next});
}
