/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:52:30 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/23 12:25:49 by hramaros         ###   ########.fr       */
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

size_t	fullfill_fd(int fd, char *eof)
{
	size_t	buffer_size;
	char	*line;

	buffer_size = 0;
	while (1)
	{
		line = readline(to_ps_two('g', NULL));
		if (ft_iseof(line, eof))
		{
			free(line);
			return (buffer_size);
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		buffer_size += ft_strlen(line) + 1;
		free(line);
	}
	return (buffer_size);
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

void	recurse_close_hd(t_hd *hd)
{
	if (!hd)
		return ;
	close(hd->fd[0]);
	close(hd->fd[1]);
	recurse_close_hd(hd->next);
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
	return (result);
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
	else
		hd = hd_cmd('a', eof);
	line += skip_hd(line);
	free(eof);
	process_hd(line);
}
