/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:52:30 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/21 10:11:36 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

int	ft_iseof(char *line, char *eof)
{
	size_t	eof_size;

	eof_size = 0;
	while (eof[eof_size])
		eof_size++;
	if (!ft_strncmp(line, eof, eof_size))
	{
		if (!line[eof_size])
			return (1);
	}
	return (0);
}

void	fullfill_fd(int fd, char *eof)
{
	char	*line;

	while (1)
	{
		line = readline(to_ps_two('g', NULL));
		if (ft_iseof(line, eof))
		{
			free(line);
			return ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	return ;
}

void	recurse_free_hd(t_hd *hd)
{
	if (!hd)
	{
		free(hd);
		return ;
	}
	recurse_free_hd(hd->next);
	free(hd);
	return ;
}

int	skip_hd(char *line)
{
	int	result;

	if (!line)
		return (0);
	result = 0;
	while (line[result])
	{
		if (!ft_strcmp("<<", line))
		{
			result += 2;
			return (result);
		}
		result++;
	}
	return (0);
}

// TOTEST
void	process_hd(char *line)
{
	t_hd	*hd;
	char	*eof;

	eof = get_eof(line);
	if (!eof)
		return ;
	hd = hd_cmd('g', NULL);
	if (!hd)
		hd = hd_cmd('i', eof);
	hd = hd_cmd('a', eof);
	line += skip_hd(line);
	free(eof);
	process_hd(line);
}
