/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:14:42 by ballain           #+#    #+#             */
/*   Updated: 2024/02/21 14:14:57 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		i_start;
	int		i_end;
	char	*r_value;

	i = 0;
	i_start = 0;
	i_end = ft_strlen(s1) - 1;
	r_value = NULL;
	while (ft_strchr(set, s1[i_start]))
		i_start++;
	while (ft_strchr(set, s1[i_end]))
		i_end--;
	if (i_start > i_end)
		return (ft_strdup(""));
	r_value = (char *)malloc(i_end - i_start + 2);
	if (!r_value)
		return (0);
	while (i_start <= i_end)
		r_value[i++] = s1[i_start++];
	r_value[i] = '\0';
	return (r_value);
}
