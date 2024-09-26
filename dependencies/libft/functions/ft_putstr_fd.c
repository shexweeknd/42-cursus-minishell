/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:31:54 by ballain           #+#    #+#             */
/*   Updated: 2024/08/05 19:30:06 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *str, int fd)
{
	int	printed;

	if (!str)
		return (ft_putstr_fd("(null)", fd));
	printed = 0;
	while (*str)
	{
		printed += ft_putchar_fd(*str, fd);
		str++;
	}
	return (printed);
}
