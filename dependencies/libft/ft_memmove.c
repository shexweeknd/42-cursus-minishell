/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:58:16 by ballain           #+#    #+#             */
/*   Updated: 2024/08/05 19:29:56 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_value;
	const char	*src_value;

	dest_value = (char *)dest;
	src_value = (const char *)src;
	if (!dest && !src)
		return (NULL);
	if (src_value <= dest_value)
	{
		dest_value += n - 1;
		src_value += n - 1;
		while (n--)
			*dest_value-- = *src_value--;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
