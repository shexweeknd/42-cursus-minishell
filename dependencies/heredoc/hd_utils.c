/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:53:46 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/21 09:36:58 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

int	_hd_occ(char *line)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	while (i < ft_strlen(line) && line[i])
	{
		if (line[i] == '<' && line[i + 1] == '<')
			result++;
		i++;
	}
	return (result);
}
