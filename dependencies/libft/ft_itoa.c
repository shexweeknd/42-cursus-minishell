/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:31:41 by ballain           #+#    #+#             */
/*   Updated: 2024/02/21 17:31:44 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(int nb, int pow)
{
	int	r_value;

	r_value = 1;
	while (pow)
	{
		r_value *= nb;
		pow--;
	}
	return (r_value);
}

static int	ft_nbint(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static	char	*ft_allocstr(int *n, int len)
{
	char	*r_value;

	r_value = NULL;
	if (*n == -2147483648)
	{
		r_value = ft_strdup("-2147483648");
		if (!r_value)
			return (0);
		return (r_value);
	}
	if (*n < 0)
	{
		r_value = (char *)malloc(len + 2);
		if (!r_value)
			return (0);
		r_value[0] = '-';
		*n *= -1;
	}
	else
	{
		r_value = (char *)malloc(len + 1);
		if (!r_value)
			return (0);
	}
	return (r_value);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*r_value;

	i = 0;
	len = ft_nbint(n);
	if (n < 0)
		i++;
	r_value = ft_allocstr(&n, len);
	if (n == -2147483648)
		return (r_value);
	if (!r_value)
		return (0);
	while (--len >= 0)
	{
		r_value[i] = (n / ft_pow(10, len)) + 48;
		n -= (n / ft_pow(10, len)) * ft_pow(10, len);
		i++;
	}
	r_value[i] = '\0';
	return (r_value);
}
