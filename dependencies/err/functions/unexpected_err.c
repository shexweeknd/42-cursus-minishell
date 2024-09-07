/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unexpected_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:29:29 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/07 12:56:23 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cmd/includes/cmd.h"
#include "../includes/m_err.h"

int	chev_check(char *prompt, int *flag, int chev_type)
{
	int	cursor;

	cursor = chev_type;
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

int	op_check(char *prompt, int *flag, int chev_type)
{
	int	cursor;

	cursor = chev_type;
	cursor += _skip_space(&prompt[cursor]);
	if (!prompt[cursor])
		return (cursor);
	if ((prompt[cursor] == '<' || prompt[cursor] == '>')
		&& !(ft_is_delimiter(prompt[cursor + 1]) || ft_is_redirect(prompt[cursor
					+ 1])))
	{
		display_unexpected_token("newline");
		*flag = 1;
	}
	else if (ft_is_delimiter(prompt[cursor]) || ft_is_redirect(prompt[cursor]))
		return (*flag = 1, display_unexpected_token(&prompt[cursor]), 0);
	return (cursor);
}

int	check_op_at_start(char *prompt)
{
	int	cursor;

	cursor = 0;
	cursor += _skip_space(prompt);
	if (!ft_strncmp(&prompt[cursor], "||", 2) || !ft_strncmp(&prompt[cursor],
			"&&", 2))
		return (display_unexpected_token(&prompt[cursor]), 0);
	else if (prompt[cursor] == '|' || prompt[cursor] == '&')
		return (display_unexpected_token(&prompt[cursor]), 0);
	return (1);
}

int	is_unexpected(char *prompt)
{
	int	flag;

	flag = 0;
	if (!check_op_at_start(prompt))
		return (1);
	while (*prompt && !flag)
	{
		if ((!ft_strncmp(prompt, ">>", 2) || !ft_strncmp(prompt, "<<", 2))
			&& !flag)
			prompt += chev_check(prompt, &flag, 2);
		else if ((*prompt == '>' || *prompt == '<') && !flag)
			prompt += chev_check(prompt, &flag, 1);
		else if ((!ft_strncmp(prompt, "||", 2) || !ft_strncmp(prompt, "&&", 2))
			&& !flag)
			prompt += op_check(prompt, &flag, 2);
		else if ((*prompt == '|' || *prompt == '&') && !flag)
			prompt += op_check(prompt, &flag, 1);
		else
			prompt++;
	}
	return (flag);
}
