/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_only_spaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:57:24 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/28 11:30:42 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_only_spaces(char *str)
{
	if (!str)
		return (0);
	while (*str && (*str == ' ' || !ft_isprint(*str)))
		str++;
	if (!*str)
		return (1);
	return (0);
}
