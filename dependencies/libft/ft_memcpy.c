/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:22:30 by ballain           #+#    #+#             */
/*   Updated: 2024/08/05 19:29:54 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;

	str = (char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n-- > 0)
		*str++ = *(char *)src++;
	return (dest);
}
