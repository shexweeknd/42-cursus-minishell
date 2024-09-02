/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:57:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/30 10:28:55 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_err.h"
#include "m_err_struct.h"

void	display_error(int err_type, char *message)
{
	if (err_type == UNEXPECTED_TOKEN)
	{
		printf("%s\n", message);
		return ;
	}
}

/**
 * TODO WILL VERIFY ALL SYNTAX RELATED ERRORS
 */
int	verify_token(char *prompt)
{
	while (ft_isspace(*prompt))
		prompt++;
	if (*prompt == '|')
		return (display_error(UNEXPECTED_TOKEN,
				"Minishell: syntax error near unexpected token `|'"), 0);
	
	return (1);
}

/**
 * TODO WILL VERIFY ALL EXECUTION RELATED ERRORS
 */
int	verify_cmd(char *prompt)
{
	(void)prompt;
	return (1);
}

int	verify_prompt(char *prompt)
{
	if (!verify_token(prompt))
		return (0);
	else if (!verify_cmd(prompt))
		return (0);
	return (1);
}
