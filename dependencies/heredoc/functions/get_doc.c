/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:18:07 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/23 10:21:24 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

char	*get_hd(int fd, size_t size)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (result);
	i = 0;
	while (size && read(fd, &result[i], 1) > 0)
	{
		size--;
		i++;
	}
	result[i] = '\0';
	return (close(fd), result);
}
