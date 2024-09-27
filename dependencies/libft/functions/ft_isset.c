/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:06:28 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/27 08:06:36 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(const char *str, char *set)
{
	int	index;

	while (*str)
	{
		index = 0;
		while (set[index])
		{
			if (*str == set[index])
				return (1);
			index++;
		}
		str++;
	}
	return (0);
}
