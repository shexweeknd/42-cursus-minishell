/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:50:42 by ballain           #+#    #+#             */
/*   Updated: 2024/02/21 17:50:43 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*r_value;

	i = 0;
	r_value = (char *)malloc(ft_strlen(s) + 1);
	if (!r_value)
		return (0);
	while (s[i] != '\0')
	{
		r_value[i] = (*f)(i, s[i]);
		i++;
	}
	r_value[i] = '\0';
	return (r_value);
}
