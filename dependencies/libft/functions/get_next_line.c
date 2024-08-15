/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:36:41 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/14 12:08:22 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_super_strjoin(char *remains, char *buffer)
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
	return (result);
}

static char	*push_line(char *buffer)
{
	char	*result;
	int		i;

	if (!buffer)
		return (NULL);
	result = malloc(sizeof(char) * (get_line_size(buffer) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		result[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		result[i] = '\n';
		result[i + 1] = '\0';
		return (result);
	}
	if (i == 0)
		return (free(result), NULL);
	result[i] = '\0';
	return (result);
}

static char	*get_remains(char *remains)
{
	int		i;
	int		j;
	char	*result;

	if (!remains)
		return (NULL);
	i = 0;
	while (remains[i] && remains[i] != '\n')
		i++;
	if (remains[i] == '\0')
		return (free(remains), NULL);
	result = malloc(sizeof(char) * (ft_strlen(&remains[i]) + 1));
	if (!result)
		return (NULL);
	j = 0;
	while (remains[++i])
		result[j++] = remains[i];
	result[j] = '\0';
	return (free(remains), result);
}

char	*get_next_line(int fd)
{
	static char	*remains;
	char		*result;
	char		buffer[42 + 1];
	int			count;

	if (fd < 0)
		return (NULL);
	count = 1;
	buffer[0] = '\0';
	while (!ft_strchr(buffer, '\n') && count)
	{
		count = read(fd, buffer, 42);
		buffer[count] = '\0';
		remains = ft_super_strjoin(remains, buffer);
	}
	result = push_line(remains);
	remains = get_remains(remains);
	if (result == NULL)
		return (free(remains), NULL);
	return (result);
}
