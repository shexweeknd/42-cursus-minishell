/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_err_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:46:07 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/27 18:06:04 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_err.h"

void	display_unexpected_chev(char *token)
{
	char	*msg;

	msg = ": syntax error near unexpected token ";
	ft_perror_fd(2, (char *[]){MSH_LOG, msg, "`", token, "'", NULL});
	if (!ft_strncmp(token, ">>", 2))
		ft_perror_fd(2, (char *[]){MSH_LOG, msg, "`", token, "'", NULL});
	else if (!ft_strncmp(token, ">|", 2))
		ft_perror_fd(2, (char *[]){MSH_LOG, msg, "`", token, "'", NULL});
	else if (!ft_strncmp(token, ">", 1))
		ft_perror_fd(2, (char *[]){MSH_LOG, msg, "`", token, "'", NULL});
	else if (!ft_strncmp(token, "<<<", 3))
		ft_perror_fd(2, (char *[]){MSH_LOG, msg, "`", token, "'", NULL});
	else if (!ft_strncmp(token, "<<", 2))
		ft_perror_fd(2, (char *[]){MSH_LOG, msg, "`", token, "'", NULL});
	else if (!ft_strncmp(token, "<>", 2))
		ft_perror_fd(2, (char *[]){MSH_LOG, msg, "`", token, "'", NULL});
	else if (!ft_strncmp(token, "<", 1))
		ft_perror_fd(2, (char *[]){MSH_LOG, msg, "`", token, "'", NULL});
	else if (!ft_strncmp(token, "newline", 7))
		ft_perror_fd(2, (char *[]){MSH_LOG, msg, "`", token, "'", NULL});
}

void	display_unexpected_pipe(char *token)
{
	char	*msg;

	msg = ": syntax error near unexpected token ";
	if (!ft_strncmp(token, "||", 2))
		ft_perror_fd(2, (char *[]){MSH_LOG, msg, "`", token, "'", NULL});
	else if (!ft_strncmp(token, "|&", 2))
		ft_perror_fd(2, (char *[]){MSH_LOG, msg, "`", token, "'", NULL});
	else if (!ft_strncmp(token, "|", 1))
		ft_perror_fd(2, (char *[]){MSH_LOG, msg, "`", token, "'", NULL});
	return ;
}

void	display_unexpected_and(char *token)
{
	char	*msg;

	msg = ": syntax error near unexpected token ";
	if (!ft_strncmp(token, "&&", 2))
		ft_perror_fd(2, (char *[]){MSH_LOG, msg, "`", token, "'", NULL});
	else if (!ft_strncmp(token, "&", 1))
		ft_perror_fd(2, (char *[]){MSH_LOG, msg, "`", token, "'", NULL});
	return ;
}

void	display_unexpected_token(char *token)
{
	display_unexpected_chev(token);
	display_unexpected_pipe(token);
	display_unexpected_and(token);
}
