/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:52:30 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/23 16:10:15 by hramaros         ###   ########.fr       */
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

// TODO: ca remplit juste les hd dans le static a chaque fois qu'on l'appelle
void	process_hd(t_eofs *eofs)
{
	t_hd	*hd;

	(void)hd;
	(void)eofs;
}
