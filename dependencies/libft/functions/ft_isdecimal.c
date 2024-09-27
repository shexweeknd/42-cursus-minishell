/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:05:11 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/27 08:11:42 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdecimal(char *base)
{
	while (*base)
	{
		if (*base < 48 || *base > 57)
			return (0);
		base++;
	}
	return (1);
}
