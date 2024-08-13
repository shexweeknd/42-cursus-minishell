/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:39:19 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/13 14:09:17 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_line_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

size_t	get_twodim_char_size(char **buffer)
{
	size_t	result;

	result = 0;
	while (*buffer)
	{
		result++;
		buffer++;
	}
	return (result);
}

void	free_two_dim(char **buffer)
{
	size_t	size;
	size_t	index;

	size = get_twodim_char_size(buffer);
	index = 0;
	while (index < (size + 1))
	{
		free(buffer[index]);
		index++;
	}
	free(buffer);
}
