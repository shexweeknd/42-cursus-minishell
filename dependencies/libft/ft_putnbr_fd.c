/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:44:06 by ballain           #+#    #+#             */
/*   Updated: 2024/02/21 18:44:08 by ballain          ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	char	r_value;
	int		exp;	

	r_value = 0;
	exp = ft_nbint(n) - 1;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		while (exp >= 0)
		{
			r_value = (n / ft_pow(10, exp)) + '0';
			n = n % ft_pow(10, exp);
			ft_putchar_fd(r_value, fd);
			exp--;
		}
	}
}
