/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:52:30 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/24 09:54:17 by hramaros         ###   ########.fr       */
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

// TODO: ca remplit juste les hd dans le static a chaque fois qu'on l'appelle
void	process_hd(t_eofs *eofs)
{
	t_hd	*hd;

	hd = hd_cmd('g', NULL);
	while (eofs)
	{
		if (!hd)
			hd_cmd('i', eofs->eof);
		else
			hd_cmd('a', eofs->eof);
		eofs = eofs->next;
	}
}
