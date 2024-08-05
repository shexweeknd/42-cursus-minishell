/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:16:46 by ballain           #+#    #+#             */
/*   Updated: 2024/02/28 14:44:29 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	*r_value;

	r_value = (unsigned int *)malloc(nmemb * size);
	if (!r_value)
		return ((void *)0);
	ft_bzero(r_value, nmemb * size);
	return ((void *)r_value);
}
