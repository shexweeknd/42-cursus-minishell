/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_extra_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:11:10 by ballain           #+#    #+#             */
/*   Updated: 2024/08/18 19:26:24 by ballain          ###   ########.fr       */
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

t_cmd	*_init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->file_in = NULL;
	cmd->file_out = NULL;
	cmd->file_append = NULL;
	cmd->heredoc = NULL;
	cmd->link_type = NONE;
	cmd->next = NULL;
	return (cmd);
}

void	*_next_cmd(void *value, t_list_type type)
{
	if (type == CMD)
		return (((t_cmd *)value)->next);
	return (value);
}

void	_add_next_cmd(void *value, void *next, t_list_type type)
{
	if (type == CMD)
		((t_cmd *)value)->next = (t_cmd *)next;
}
