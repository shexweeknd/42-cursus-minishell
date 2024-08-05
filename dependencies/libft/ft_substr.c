/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:28:19 by ballain           #+#    #+#             */
/*   Updated: 2024/02/29 16:25:05 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(char const *s, unsigned int start, size_t len)
{
	size_t	r_value;
	size_t	len_s;
	size_t	len_r;

	r_value = 0;
	len_s = ft_strlen(s);
	len_r = start + len;
	if (len_r >= len_s)
		r_value = len_s - start + 1;
	else
		r_value = len + 1;
	if (start >= len_s)
		r_value = (int)(sizeof(char) * 1);
	return (r_value);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		len_s;
	char		*r_value;

	i = 0;
	len_s = ft_strlen(s);
	r_value = (char *)malloc(ft_size(s, start, len));
	if (!r_value)
		return (0);
	if (start >= len_s)
	{
		r_value[i] = '\0';
		return (r_value);
	}
	while (i < len)
	{
		if (s[start + i] == '\0')
			break ;
		r_value[i] = s[start + i];
		i++;
	}
	r_value[i] = '\0';
	return (r_value);
}
