/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:18:04 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/11 14:18:18 by hramaros         ###   ########.fr       */
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

// TODO FORENSICS OF PROMPT THAT DISPLAYS PS2
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
