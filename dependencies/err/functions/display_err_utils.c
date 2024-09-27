/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_err_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:46:07 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/27 08:24:20 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_err.h"

void	display_unexpected_chev(char *token)
{
	char	*msg;

	msg = ": syntax error near unexpected token ";
	if (!ft_strncmp(token, ">>", 2))
		ft_printf_fd("%s%s`%.2s'\n", 2, MSH_LOG, msg, token);
	else if (!ft_strncmp(token, ">|", 2))
		ft_printf_fd("%s%s`%.2s'\n", 2, MSH_LOG, msg, token);
	else if (!ft_strncmp(token, ">", 1))
		ft_printf_fd("%s%s`%.1s'\n", 2, MSH_LOG, msg, token);
	else if (!ft_strncmp(token, "<<<", 3))
		ft_printf_fd("%s%s`%.3s'\n", 2, MSH_LOG, msg, token);
	else if (!ft_strncmp(token, "<<", 2))
		ft_printf_fd("%s%s`%.2s'\n", 2, MSH_LOG, msg, token);
	else if (!ft_strncmp(token, "<>", 2))
		ft_printf_fd("%s%s`%.2s'\n", 2, MSH_LOG, msg, token);
	else if (!ft_strncmp(token, "<", 1))
		ft_printf_fd("%s%s`%.1s'\n", 2, MSH_LOG, msg, token);
	else if (!ft_strncmp(token, "newline", 7))
		ft_printf_fd("%s%s`%.7s'\n", 2, MSH_LOG, msg, token);
}

void	display_unexpected_pipe(char *token)
{
	char	*msg;

	msg = ": syntax error near unexpected token ";
	if (!ft_strncmp(token, "||", 2))
		ft_printf_fd("%s%s`%.2s'\n", 2, MSH_LOG, msg, token);
	else if (!ft_strncmp(token, "|&", 2))
		ft_printf_fd("%s%s`%.2s'\n", 2, MSH_LOG, msg, token);
	else if (!ft_strncmp(token, "|", 1))
		ft_printf_fd("%s%s`%.1s'\n", 2, MSH_LOG, msg, token);
	return ;
}

void	display_unexpected_and(char *token)
{
	char	*msg;

	msg = ": syntax error near unexpected token ";
	if (!ft_strncmp(token, "&&", 2))
		ft_printf_fd("%s%s`%.2s'\n", 2, MSH_LOG, msg, token);
	else if (!ft_strncmp(token, "&", 1))
		ft_printf_fd("%s%s`%.1s'\n", 2, MSH_LOG, msg, token);
	return ;
}

void	display_unexpected_token(char *token)
{
	display_unexpected_chev(token);
	display_unexpected_pipe(token);
	display_unexpected_and(token);
}
