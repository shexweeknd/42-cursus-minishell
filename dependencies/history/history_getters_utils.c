/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_getters_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:50:45 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/13 12:54:33 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

size_t	count_files_line(char *file_path)
{
	int		fd;
	size_t	result;
	char	*temp;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	temp = get_next_line(fd);
	result = 0;
	while (temp)
	{
		free(temp);
		result++;
		temp = get_next_line(fd);
	}
	return (close(fd), result);
}

char	**parse_twodim(char *history_path)
{
	char	**result;
	size_t	file_lines_size;
	size_t	index;
	int		fd;

	fd = open(history_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file_lines_size = count_files_line(history_path);
	result = malloc(sizeof(char *) * (file_lines_size + 1));
	if (!result)
		return (close(fd), NULL);
	index = 0;
	while (index < file_lines_size)
	{
		result[index] = get_next_line(fd);
		if (!result)
			return (close(fd), free(result), NULL);
		index++;
	}
	result[file_lines_size] = NULL;
	return (close(fd), result);
}
