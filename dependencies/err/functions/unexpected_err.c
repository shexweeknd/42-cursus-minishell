/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unexpected_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:29:29 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/04 15:45:34 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cmd/includes/cmd.h"
#include "../includes/m_err.h"

int	handle_pipe_at_start(char *cmd)
{
	if (*cmd == '|')
		return (printf("Minishell: syntax error near unexpected token `||'\n"),
			1);
	return (printf("Minishell: syntax error near unexpected token `|'\n"), 1);
}

int	handle_app_at_start(char *cmd)
{
	if (ft_is_delimiter(*cmd) || ft_is_redirect(*cmd))
		return (printf("Minishell: syntax error near unexpected token `%.2s'\n",
				cmd), 1);
	return (printf("Minishell: syntax error near unexpected token `newline'\n"),
		1);
}

int	handle_rout_at_start(char *cmd)
{
	if (ft_is_delimiter(*cmd) || !*cmd)
		return (printf("Minishell: syntax error near unexpected token `newline'\n"),
			1);
	if (ft_is_redirect(*cmd))
		return (printf("Minishell: syntax error near unexpected token `%.2s'\n",
				cmd), 1);
	return (0);
}

int	is_unexpected_at_start(char *cmd)
{
	cmd += _skip_space(cmd);
	if (!*cmd)
		return (1);
	if (*cmd == '|')
		return (handle_pipe_at_start(cmd + 1));
	if (*cmd == '>')
	{
		if (!ft_strncmp(cmd, ">>", 2))
			return (cmd += _skip_space(cmd + 2), handle_app_at_start(cmd + 2));
		else
			return (cmd += _skip_space(cmd + 1), handle_rout_at_start(cmd + 1));
	}
	// if (*cmd == '<')
	// 	return (handle_rin_at_start(cmd + 1));
	// if (*cmd == '&')
	// 	return (handle_and_at_start(cmd + 1));
	return (0);
}
