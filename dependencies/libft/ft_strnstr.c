/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:39:23 by ballain           #+#    #+#             */
/*   Updated: 2024/08/05 19:30:34 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		len_little;

	i = 0;
	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (ft_strncmp(&big[i], little, len_little) == 0)
		{
			if ((i + len_little) <= len)
				return ((char *)(&big[i]));
		}
		i++;
	}
	return (0);
}
