/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_extra_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:11:10 by ballain           #+#    #+#             */
/*   Updated: 2024/08/15 13:32:01 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int	_skip_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (ft_isspace(*(str++)))
		i++;
	return (i);
}

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

void	*_next_cmd(void *value, t_list_type type)
{
	if (type == CMD)
		return (((t_cmd *)value)->next);
	if (type == IO_ARG)
		return (((t_io_arg *)value)->next);
	return (value);
}

void	_add_next_cmd(void *value, void *next, t_list_type type)
{
	if (type == CMD)
		((t_cmd *)value)->next = (t_cmd *)next;
	if (type == IO_ARG)
		((t_io_arg *)value)->next = (t_io_arg *)next;
}
