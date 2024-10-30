/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unexpected_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:29:29 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/30 07:51:07 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_err.h"

int	chev_check(char *prompt, int *flag, int chev_type, int lvl)
{
	int	cursor;

	cursor = chev_type;
	cursor += _skip_space(&prompt[cursor]);
	if (!lvl && (ft_is_delimiter(prompt[cursor])
			|| ft_is_redirect(prompt[cursor])))
		return (*flag = 1, display_unexpected_token(&prompt[cursor]), 0);
	if (!prompt[cursor] && lvl)
	{
		display_unexpected_token("newline");
		*flag = 1;
	}
	return (cursor);
}

int	op_check(char *prompt, int *flag, int chev_type, int lvl)
{
	int	cursor;

	cursor = chev_type;
	cursor += _skip_space(&prompt[cursor]);
	if (!prompt[cursor])
		return (cursor);
	if ((prompt[cursor] == '<' || prompt[cursor] == '>')
		&& is_only_spaces(&prompt[cursor + 1]) && lvl)
	{
		display_unexpected_token("newline");
		*flag = 1;
	}
	else if (ft_is_delimiter(prompt[cursor]))
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
	else if ((!ft_strncmp(&prompt[cursor], ">>", 2)
			|| !ft_strncmp(&prompt[cursor], "<<", 2))
		&& is_only_spaces(&prompt[cursor + 2]))
		return (display_unexpected_token("newline"), 0);
	else if ((prompt[cursor] == '>' || prompt[cursor] == '<')
		&& is_only_spaces(&prompt[cursor + 1]))
		return (display_unexpected_token("newline"), 0);
	return (1);
}

int	is_unexpected(char *prompt, int lvl)
{
	int	flag;

	flag = 0;
	if (!check_op_at_start(prompt))
		return (1);
	while (*prompt && !flag)
	{
		if (*prompt == '"')
			prompt += skip_until(prompt, '"');
		else if (*prompt == '\'')
			prompt += skip_until(prompt, '\'');
		else if ((!ft_strncmp(prompt, ">>", 2) || !ft_strncmp(prompt, "<<", 2))
			&& !flag)
			prompt += chev_check(prompt, &flag, 2, lvl);
		else if ((*prompt == '>' || *prompt == '<') && !flag)
			prompt += chev_check(prompt, &flag, 1, lvl);
		else if ((!ft_strncmp(prompt, "||", 2) || !ft_strncmp(prompt, "&&", 2))
			&& !flag)
			prompt += op_check(prompt, &flag, 2, lvl);
		else if ((*prompt == '|' || *prompt == '&') && !flag)
			prompt += op_check(prompt, &flag, 1, lvl);
		else
			prompt++;
	}
	return (flag);
}
