/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:16:46 by ballain           #+#    #+#             */
/*   Updated: 2024/08/12 14:16:47 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	*r_value;

	r_value = (unsigned int *)malloc(nmemb * size);
	if (!r_value)
		return ((void *)0);
	ft_bzero(r_value, nmemb * size);
	return ((void *)r_value);
}
