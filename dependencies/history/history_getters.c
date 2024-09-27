/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_getters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:50:45 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/27 10:40:20 by hramaros         ###   ########.fr       */
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
		return (first_elem);
	if (!first_elem)
	{
		first_elem = malloc(sizeof(t_hist_elem));
		if (!first_elem)
			return (NULL);
		first_elem->command = ft_nl_to_zero(command);
		first_elem->line_nbr = 0;
		first_elem->is_offset = 0;
		first_elem->next = NULL;
		return (add_history(command), first_elem);
	}
	backup = first_elem;
	while (first_elem->next)
		first_elem = first_elem->next;
	first_elem->next = malloc(sizeof(t_hist_elem));
	if (!first_elem->next)
		return (free_lchistory(backup), NULL);
	first_elem->next->command = ft_nl_to_zero(command);
	first_elem->next->line_nbr = first_elem->line_nbr + 1;
	first_elem->next->is_offset = 0;
	return (add_history(command), first_elem->next->next = NULL, backup);
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
	if (!elem->next && !elem->is_offset)
		return (NULL);
	while (elem && !elem->is_offset)
		elem = elem->next;
	return (elem);
}
