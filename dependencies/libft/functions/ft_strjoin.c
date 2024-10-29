/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:38:53 by ballain           #+#    #+#             */
/*   Updated: 2024/10/29 13:59:44 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*r_value;

	i = 0;
	r_value = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r_value)
		return (0);
	while (s1 && *s1 != '\0')
	{
		r_value[i++] = *s1;
		s1++;
	}
	while (s2 && *s2 != '\0')
	{
		r_value[i++] = *s2;
		s2++;
	}
	r_value[i] = '\0';
	return (r_value);
}
