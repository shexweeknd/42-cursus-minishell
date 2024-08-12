/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_extra_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:11:10 by ballain           #+#    #+#             */
/*   Updated: 2024/08/12 15:28:08 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

t_io_arg	*_init_io_arg(t_redirect redirect, char *arg)
{
	t_io_arg	*r_io_arg;

	r_io_arg = (t_io_arg *)malloc(sizeof(t_io_arg));
	if (!r_io_arg)
		return (NULL);
	r_io_arg->redirect = redirect;
	r_io_arg->arg = arg;
	r_io_arg->next = NULL;
	return (r_io_arg);
}

t_cmd	*_init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->name = NULL;
	cmd->option = NULL;
	cmd->arg = NULL;
	cmd->io_arg = NULL;
	cmd->link_type = NONE;
	cmd->next = NULL;
	return (cmd);
}
