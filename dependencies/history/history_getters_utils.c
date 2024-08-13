/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_getters_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:50:45 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/13 15:19:12 by hramaros         ###   ########.fr       */
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

t_hist_elem	*ft_append_hist_elem(t_hist_elem *first_elem, char *command)
{
	t_hist_elem	*backup;

	if (!command)
		return (NULL);
	if (!first_elem)
	{
		first_elem = malloc(sizeof(t_hist_elem));
		if (!first_elem)
			return (NULL);
		first_elem->command = command;
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
	first_elem->next->command = command;
	first_elem->next->is_offset_to_write = 0;
	first_elem->next->next = NULL;
	return (backup);
}
