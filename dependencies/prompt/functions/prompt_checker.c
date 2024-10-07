/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:18:04 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/07 14:46:39 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int	is_pipe_at_end(char *line)
{
	int	cursor;

	cursor = 0;
	while (line[cursor])
		cursor++;
	while (cursor && line[--cursor] == ' ')
		;
	if (line[cursor] == '|')
		return (1);
	return (0);
}

int	is_and_at_end(char *line)
{
	int	cursor;

	cursor = 0;
	while (line[cursor])
		cursor++;
	while (cursor && line[cursor--] == ' ')
		;
	if (line[cursor] == '&' && cursor >= 2)
	{
		if (line[cursor - 1] == '&')
			return (1);
	}
	return (0);
}

int	is_uncomplete_line(char *line)
{
	if (!line)
		return (0);
	if (is_pipe_at_end(line))
		return (1);
	if (is_and_at_end(line))
		return (1);
	return (0);
}
