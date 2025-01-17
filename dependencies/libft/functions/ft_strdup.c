/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:33:14 by ballain           #+#    #+#             */
/*   Updated: 2024/09/11 15:25:37 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*r_value;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	r_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!r_value)
		return (0);
	while (i < len)
	{
		r_value[i] = s[i];
		i++;
	}
	r_value[i] = '\0';
	return (r_value);
}
