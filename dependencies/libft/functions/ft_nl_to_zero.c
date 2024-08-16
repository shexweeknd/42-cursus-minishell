/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nl_to_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:46:13 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/16 13:46:23 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nl_to_zero(char *str)
{
	char	*result;

	if (!str)
		return (str);
	result = str;
	while (*str)
	{
		if (*str == '\n')
			*str = '\0';
		str++;
	}
	return (result);
}
