/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:29:12 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/25 19:00:27 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

int	is_valid_hd(char *line)
{
	int	flag;
	int	lvl;

	lvl = 0;
	flag = 0;
	if (!ft_strncmp(line, "<<", 2))
	{
		chev_check(line, &flag, 2, lvl);
	}
	return (!flag);
}

int	valid_before_hd(char *line, int lvl)
{
	int	flag;

	flag = 0;
	while (*line && !flag && ft_strncmp(line, "<<", 2))
	{
		if (!ft_strncmp(line, ">>", 2))
			line += chev_check(line, &flag, 2, lvl);
		if (!ft_strncmp(line, "<<", 2))
			break ;
		else if ((*line == '>' || *line == '<') && !flag)
			line += chev_check(line, &flag, 1, lvl);
		else if ((!ft_strncmp(line, "||", 2) || !ft_strncmp(line, "&&", 2))
			&& !flag)
			line += op_check(line, &flag, 2, lvl);
		else if ((*line == '|' || *line == '&') && !flag)
			line += op_check(line, &flag, 1, lvl);
		else
			line++;
	}
	return (!flag);
}

int	is_hd_uncomplete(char *line)
{
	if (!ft_strncmp(line, "<<", 2))
	{
		if (is_only_spaces(line + 2))
			return (1);
	}
	return (0);
}

int	hd_check_syntax_err(char *prompt)
{
	t_eofs	*eofs;

	if (!check_op_at_start(prompt))
		return (1);
	eofs = NULL;
	while (*prompt)
	{
		if (!valid_before_hd(prompt, 0))
			return (process_hd(eofs), 1);
		prompt += skip_until_hd(prompt);
		if (is_hd_uncomplete(prompt))
			return (process_hd(eofs), 0);
		if (!is_valid_hd(prompt))
			return (process_hd(eofs), 1);
		eofs = append_eofs(eofs, get_eof(prompt));
		if (!eofs)
			return (process_hd(eofs), 1);
		prompt += skip_hd_eof(prompt);
	}
	return (process_hd(eofs), 0);
}
