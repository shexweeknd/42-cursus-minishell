/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:31:35 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/23 09:20:51 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

int	eof_size(char *line)
{
	int	result;

	result = 0;
	while (line[result] && !ft_isspace(line[result]))
		result++;
	return (result);
}

char	*get_eof(char *line)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (line[i] && line[i + 1])
	{
		if (!ft_strncmp(&line[i], "<<", 2))
		{
			i += 2;
			while (ft_isspace(line[i]))
				i++;
			result = malloc(sizeof(char) * (eof_size(&line[i]) + 1));
			if (!result)
				return (NULL);
			j = 0;
			while (line[i] && !ft_isspace(line[i]))
				result[j++] = line[i++];
			result[j] = '\0';
			return (result);
		}
		i++;
	}
	return (NULL);
}
