/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:55:23 by ballain           #+#    #+#             */
/*   Updated: 2024/09/19 12:44:05 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char *str[])
{
	int		i;
	int		len;
	char	*r_value;

	i = 0;
	len = 0;
	while (str[i])
		len += ft_strlen(str[i++]);
	r_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!r_value)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (**str)
			r_value[i++] = *(*str)++;
		str++;
	}
	r_value[i] = 0;
	return (r_value);
}
