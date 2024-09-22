/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlen_strtab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:42:57 by ballain           #+#    #+#             */
/*   Updated: 2024/09/18 16:42:58 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getlen_strtab(char *tab[])
{
	int	len;

	len = 0;
	while (*tab)
	{
		len++;
		tab++;
	}
	return (len);
}
