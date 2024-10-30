/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:57:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/30 07:52:54 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_err.h"

int	is_heredoc_to_process(char *prompt)
{
	if (!prompt || !*prompt)
		return (0);
	while (*prompt)
	{
		if (*prompt == '"')
			prompt += skip_until(prompt, '"');
		else if (*prompt == '\'')
			prompt += skip_until(prompt, '\'');
		if (!ft_strncmp(prompt, "<<", 2))
			return (1);
		if (*prompt)
			prompt++;
	}
	return (0);
}

int	check_syntax_err(char *prompt, int with_hd)
{
	int	flag;

	flag = 0;
	if (is_only_spaces(prompt))
		flag = 1;
	if (is_heredoc_to_process(prompt) && with_hd)
		flag = hd_check_syntax_err(prompt);
	else if (!flag && is_unexpected(prompt, 0))
		flag = 1;
	if (!flag && is_unexpected(prompt, 1))
		flag = 1;
	if (flag)
		set_status(2);
	return (flag);
}
