/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:15:14 by ballain           #+#    #+#             */
/*   Updated: 2024/09/23 13:19:15 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str_1;
	unsigned char	*str_2;

	if (!s1 || !s2)
		return (2048);
	i = 0;
	str_1 = (unsigned char *)s1;
	str_2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str_1[i] != str_2[i])
			return (str_1[i] - str_2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
