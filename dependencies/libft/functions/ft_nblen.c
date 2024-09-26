/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:46:45 by ballain           #+#    #+#             */
/*   Updated: 2024/09/26 09:48:20 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nblen(int nb)
{
	int	len;

	len = 0;
	if (!nb)
		return (1);
	if (nb < 0)
		len++;
	while (nb)
		nb /= (len++, 10);
	return (len);
}

