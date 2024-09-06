/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_err_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:46:07 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/06 09:16:01 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cmd/includes/cmd.h"
#include "../includes/m_err.h"

void	display_unexpected_token(char *token)
{
	if (!ft_strncmp(token, ">>", 2))
		printf("Minishell: syntax error near unexpected token `%.2s'\n", token);
	else if (!ft_strncmp(token, ">|", 2))
		printf("Minishell: syntax error near unexpected token `%.2s'\n", token);
	else if (!ft_strncmp(token, ">", 1))
		printf("Minishell: syntax error near unexpected token `%.1s'\n", token);
	else if (!ft_strncmp(token, "<<<", 3))
		printf("Minishell: syntax error near unexpected token `%.3s'\n", token);
	else if (!ft_strncmp(token, "<<", 2))
		printf("Minishell: syntax error near unexpected token `%.2s'\n", token);
	else if (!ft_strncmp(token, "<>", 2))
		printf("Minishell: syntax error near unexpected token `%.2s'\n", token);
	else if (!ft_strncmp(token, "<", 1))
		printf("Minishell: syntax error near unexpected token `%.1s'\n", token);
	else if (!ft_strncmp(token, "newline", 7))
		printf("Minishell: syntax error near unexpected token `%.7s'\n", token);
}
