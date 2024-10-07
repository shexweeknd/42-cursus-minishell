/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:35:25 by ballain           #+#    #+#             */
/*   Updated: 2024/10/07 13:35:51 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isvar(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	if (*str == '$' && str++)
	{
		if (!*str || *str == '?' || ft_isdigit(*str) || \
			(!ft_isalpha(*str) && *str != '_'))
			return (1);
		while (*str && (ft_isalpha(*str) || *str == '_'))
		{
			str++;
			len++;
		}
		return (len);
	}
	return (0);
}
