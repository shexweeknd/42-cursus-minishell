/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:39:28 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/27 18:11:54 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

t_hist_elem	*new_history(char *command, int position)
{
	t_hist_elem	*result;

	if (!command)
	{
		ft_perror_fd(2, (char *[]){"The command to parse in history is null.", \
		NULL});
		return (NULL);
	}
	result = malloc(sizeof(t_hist_elem));
	if (!result)
	{
		ft_perror_fd(2, (char *[]){"Failed to malloc the command history.", \
		NULL});
		return (NULL);
	}
	result->command = ft_strdup(command);
	result->line_nbr = position;
	result->is_offset = 0;
	result->next = NULL;
	return (result);
}

t_hist_elem	*get_history(char *file_path)
{
	t_hist_elem	*result;
	int			fd;
	size_t		index;
	size_t		size;

	fd = open(file_path, O_RDONLY | O_CREAT, 0644);
	if (fd < 0)
		return (0);
	result = NULL;
	size = count_files_line(file_path);
	index = 0;
	while (index < (size + 1))
	{
		result = ft_append_hist_elem(result, get_next_line(fd));
		index++;
	}
	if (result)
		ft_get_last_history(result)->is_offset = 1;
	return (close(fd), result);
}

int	set_history(t_hist_elem *hist_elem, char *file_path)
{
	int		fd;
	char	*remains;

	fd = open(file_path, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		return (ft_perror_fd(2, (char *[]){"Failed to write the history", \
			NULL}), 0);
	go_to_offset(fd, ft_get_history_offsetted(hist_elem));
	remains = get_things_after_offset(fd);
	close(fd);
	fd = open(file_path, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		return (ft_perror_fd(2, (char *[]){"Failed to write the history", \
			NULL}), 0);
	go_to_offset(fd, ft_get_history_offsetted(hist_elem));
	if (ft_get_history_offsetted(hist_elem))
		write_cmd_typed_after_offset(fd,
			ft_get_history_offsetted(hist_elem)->next);
	else
		write_cmd_typed_after_offset(fd, hist_elem);
	write(fd, remains, ft_strlen(remains));
	return (free_lchistory(hist_elem), free(remains), close(fd), 1);
}
