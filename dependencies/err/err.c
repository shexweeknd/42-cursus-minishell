/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:57:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/04 11:00:03 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cmd/includes/cmd.h"
#include "../cmd/includes/cmd_struct.h"
#include "m_err.h"
#include "m_err_struct.h"

void	display_error(int err_type, t_cmd *cmd)
{
	if (err_type == UNEXPECTED_TOKEN)
	{
		printf("Minishell: syntax error near unexpected token `%s'\n",
			get_link_char(cmd->link_type));
		return ;
	}
}

int	is_unexpected_token(t_cmd *cmd)
{
	while (cmd)
	{
		if (!cmd->nb_arg)
			return (display_error(UNEXPECTED_TOKEN, cmd), 1);
		cmd = cmd->next;
	}
	return (0);
}

t_cmd	*verify_cmds(t_cmd *cmd)
{
	if (is_unexpected_token(cmd))
		return (ft_free_cmds(cmd), NULL);
	return (cmd);
}
