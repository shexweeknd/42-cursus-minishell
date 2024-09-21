/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:31:35 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/21 09:39:07 by hramaros         ###   ########.fr       */
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
	while (line[i])
	{
		if (!ft_strcmp(&line[i], "<<"))
		{
			i += 2;
			while (ft_isspace(line[i]))
				i++;
			result = malloc(sizeof(char) * (eof_size(&line[i]) + 1));
			if (!result)
				return (NULL);
			j = 0;
			while (!ft_isspace(line[i]))
				result[j++] = line[i++];
			return (result);
		}
		i++;
	}
	return (NULL);
}
