/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:50:14 by ballain           #+#    #+#             */
/*   Updated: 2024/09/25 16:50:14 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	_skip_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (ft_isspace(*(str++)))
		i++;
	return (i);
}
