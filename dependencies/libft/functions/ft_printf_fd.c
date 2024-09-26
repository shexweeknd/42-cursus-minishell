/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:17:34 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/26 17:09:21 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(const char *str, char *set)
{
	int	index;

	while (*str)
	{
		index = 0;
		while (set[index])
		{
			if (*str == set[index])
				return (1);
			index++;
		}
		str++;
	}
	return (0);
}

int	is_decimal(char *base)
{
	while (*base)
	{
		if (*base < 48 || *base > 57)
			return (0);
		base++;
	}
	return (1);
}

int	recurse_nbr(long nbr, char *base, int fd)
{
	int	printed;

	printed = 0;
	if (nbr < (long)ft_strlen(base))
		printed += ft_putchar_fd(base[nbr % ft_strlen(base)], fd);
	else if (nbr >= (long)ft_strlen(base))
	{
		printed += recurse_nbr(nbr / ft_strlen(base), base, fd);
		printed += ft_putchar_fd(base[nbr % ft_strlen(base)], fd);
	}
	return (printed);
}

int	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int		printed;
	long	n;

	printed = 0;
	n = nbr;
	if (nbr < 0)
	{
		printed += ft_putchar_fd('-', fd);
		n *= -1;
	}
	printed += recurse_nbr(n, base, fd);
	return (printed);
}

int	ft_putx_fd(unsigned int nbr, char *base, int fd)
{
	int		printed;
	long	n;

	printed = 0;
	n = nbr;
	printed += recurse_nbr(n, base, fd);
	return (printed);
}

int	ft_putformat_fd(const char *str, va_list ap, int fd)
{
	int		printed;
	char	*set;

	set = "csdx%";
	if (!ft_isset(str, set))
		return (0);
	printed = 0;
	if (*str == 'c')
		printed += ft_putchar_fd(va_arg(ap, int), fd);
	else if (*str == 's')
		printed += ft_putstr_fd(va_arg(ap, char *), fd);
	else if (*str == 'd')
		printed += ft_putnbr_base_fd(va_arg(ap, int), "0123456789", fd);
	else if (*str == 'x')
		printed += ft_putx_fd(va_arg(ap, int), "0123456789abcdef", fd);
	else if (*str == 'X')
		printed += ft_putx_fd(va_arg(ap, int), "0123456789ABCDEF", fd);
	else if (*str == '%')
		printed += ft_putchar_fd('%', fd);
	return (printed);
}

int	ft_printf_fd(const char *str, ...)
{
	va_list	ap;
	int		printed;
    int     fd;

	va_start(ap, str);
    fd = va_arg(ap, int);
	printed = 0;
	while (*str)
	{
		if (*str == '%')
			printed += ft_putformat_fd(++str, ap, fd);
		else
			printed += ft_putchar_fd(*str, fd);
		str++;
	}
	va_end(ap);
	return (printed);
}
