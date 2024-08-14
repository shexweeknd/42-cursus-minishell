/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_getters_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:50:45 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/14 15:34:10 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

size_t	count_files_line(char *history_path)
{
	int		fd;
	size_t	size;
	char	buffer[2048];

	fd = open(history_path, O_RDONLY);
	if (fd < 0)
		return (0);
	ft_bzero(buffer, 2048);
	size = 0;
	while (read(fd, buffer, 2048) > 0)
	{
		size += ft_get_occ(buffer, '\n');
		ft_bzero(buffer, 2048);
	}
	return (close(fd), size);
}

static char	*ft_nl_to_zero(char *str)
{
	char	*result;

	if (!str)
		return (str);
	result = str;
	while (*str)
	{
		if (*str == '\n')
			*str = '\0';
		str++;
	}
	return (result);
}

t_hist_elem	*ft_append_hist_elem(t_hist_elem *first_elem, char *command,
		int position)
{
	t_hist_elem	*backup;

	if (!command)
		return (first_elem);
	if (!first_elem)
	{
		first_elem = malloc(sizeof(t_hist_elem));
		if (!first_elem)
			return (NULL);
		first_elem->command = ft_nl_to_zero(command);
		first_elem->line_number = position;
		first_elem->is_offset_to_write = 0;
		first_elem->next = NULL;
		return (first_elem);
	}
	backup = first_elem;
	while (first_elem->next)
		first_elem = first_elem->next;
	first_elem->next = malloc(sizeof(t_hist_elem));
	if (!first_elem->next)
		return (free_history(backup), NULL);
	first_elem->next->command = ft_nl_to_zero(command);
	first_elem->line_number = position;
	first_elem->next->is_offset_to_write = 0;
	return (first_elem->next->next = NULL, backup);
}

t_hist_elem	*ft_get_last_history(t_hist_elem *elem)
{
	if (!elem)
		return (elem);
	while (elem->next)
		elem = elem->next;
	return (elem);
}

t_hist_elem	*ft_get_history_offsetted(t_hist_elem *elem)
{
	if (!elem)
		return (elem);
	while (!elem->is_offset_to_write && elem->next)
		elem = elem->next;
	return (elem);
}
