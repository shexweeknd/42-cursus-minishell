/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_occ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:35:24 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/22 19:39:52 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_occ(char *str, char c)
{
	size_t	occ;

	if (!str)
		return (0);
	occ = 0;
	while (*str)
	{
		if (*str == c)
			occ++;
		str++;
	}
	return (occ);
}
