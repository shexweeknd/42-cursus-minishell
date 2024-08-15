/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:20:51 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/14 19:06:25 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void	go_to_offset(int fd, t_hist_elem *hist_elem)
{
	char	buf;
	int		line_pos;

	line_pos = 0;
	while (line_pos < hist_elem->line_number && read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			line_pos++;
	}
}
static char	*ft_super_strjoin_and_free(char *remains, char *buffer)
{
	char	*result;
	int		i;
	int		j;

	if (!remains && !buffer)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(remains) + ft_strlen(buffer)
				+ 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	if (remains)
	{
		while (remains[i])
			result[j++] = remains[i++];
	}
	i = 0;
	while (buffer[i])
		result[j++] = buffer[i++];
	result[ft_strlen(remains) + ft_strlen(buffer)] = '\0';
	free(remains);
	free(buffer);
	return (result);
}

char	*get_things_after_offset(int fd)
{
	char	*result;
	char	*line;

	result = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		result = ft_super_strjoin_and_free(result, line);
	}
	return (close(fd), result);
}
