/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:01:59 by ballain           #+#    #+#             */
/*   Updated: 2024/02/20 14:02:01 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if ((int)size >= 0 && size < len_dst)
		return (size + len_src);
	if ((int)size < 0)
		ft_strlcpy(&dst[len_dst], src, len_src + 1);
	else
		ft_strlcpy(&dst[len_dst], src, size - len_dst);
	return (len_dst + len_src);
}
