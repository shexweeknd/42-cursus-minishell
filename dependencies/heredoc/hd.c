/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:52:30 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/15 09:21:49 by hramaros         ###   ########.fr       */
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

size_t	fullfill_fd(int fd, t_eofs *eof)
{
	size_t	buffer_size;
	char	*line;
	char	*warn_msg;

	warn_msg = ": warning: here-document at line 1 delimited by end-of-file";
	line = NULL;
	buffer_size = 0;
	while (1)
	{
		line = readline(to_ps_two('g', NULL));
		if (!line || ft_iseof(line, eof->eof))
			break ;
		if (eof->have_expanded)
			buffer_size += ft_write_hd(fd, line) + 1;
		else
			write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		buffer_size += ft_strlen(line) + 1;
		free(line);
	}
	if (!line && !get_status())
		ft_perror_fd(2, (char *[]){MSH_LOG, warn_msg, " (wanted `", eof->eof,
			"')", NULL});
	return (close(fd), free(line), buffer_size);
}

void	process_hd(t_eofs *eofs)
{
	t_hd	*hd;
	t_eofs	*eofs_addr;

	signal(SIGINT, sec_sig_handler);
	eofs_addr = eofs;
	hd = hd_cmd('g', NULL);
	while (eofs)
	{
		if (!hd)
			hd = hd_cmd('i', eofs);
		else
			hd = hd_cmd('a', eofs);
		eofs = eofs->next;
	}
	free_eofs(eofs_addr);
}
