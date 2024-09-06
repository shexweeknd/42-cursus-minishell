/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unexpected_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:29:29 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/06 09:27:00 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cmd/includes/cmd.h"
#include "../includes/m_err.h"

int	appcheck(char *prompt, int *flag)
{
	int	cursor;

	cursor = 2;
	cursor += _skip_space(&prompt[cursor]);
	if (ft_is_delimiter(prompt[cursor]) || ft_is_redirect(prompt[cursor]))
		return (*flag = 1, display_unexpected_token(&prompt[cursor]), 0);
	if (!prompt[cursor])
	{
		display_unexpected_token("newline");
		*flag = 1;
	}
	return (cursor);
}

int	routcheck(char *prompt, int *flag)
{
	int	cursor;

	cursor = 1;
	if (prompt[cursor] == '>')
		return (0);
	cursor += _skip_space(&prompt[cursor]);
	if (ft_is_delimiter(prompt[cursor]) || ft_is_redirect(prompt[cursor]))
		return (*flag = 1, display_unexpected_token(&prompt[cursor]), 0);
	if (!prompt[cursor])
	{
		display_unexpected_token("newline");
		*flag = 1;
	}
	return (cursor);
}

int	is_unexpected(char *prompt)
{
	int	flag;

	flag = 0;
	while (*prompt)
	{
		if (!ft_strncmp(prompt, ">>", 2) && !flag)
			prompt += appcheck(prompt, &flag);
		else if (*prompt == '>' && !flag)
			prompt += routcheck(prompt, &flag);
		else
			prompt++;
	}
	// if (*cmd == '<')
	// 	return (handle_rin(cmd + 1));
	// if (*cmd == '&')
	// 	return (handle_and(cmd + 1));
	return (flag);
}
