/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_occ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:35:24 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/13 14:57:05 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_occ(char *str, char c)
{
	size_t	occ;

	if (!str)
		return (0);
	occ = 0;
	while (*str)
	{
		if (*str == c)
			occ++;
		str++;
	}
	return (occ);
}
