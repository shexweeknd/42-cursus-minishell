/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:37:40 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/26 17:00:00 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnbr(char *str)
{
	if (!str)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (!*str)
		return (0);
	while (ft_isdigit(*str))
	{
		str++;
		if (!*str || ft_isspace(*str))
			return (1);
		if (*str && !ft_isdigit(*str))
			return (0);
	}
	return (0);
}
