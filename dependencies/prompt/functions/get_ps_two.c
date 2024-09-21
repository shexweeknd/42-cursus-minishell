/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ps_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:36:00 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/21 08:57:54 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

char	*to_ps_two(char cmd, char *value)
{
	static char	*ps_two = "> ";

	if (cmd == 's')
		ps_two = value;
	return (ps_two);
}
