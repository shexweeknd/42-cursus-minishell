/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:29:12 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/23 10:31:35 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

int	hd_err(char *line)
{
	int	flag;

	flag = 0;
	while (*line && !flag)
	{
		if (!ft_strncmp(line, "<<", 2) && !flag)
			line += chev_check(line, &flag, 2);
		else
			line++;
	}
	return (flag);
}
