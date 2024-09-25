/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ps_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:36:00 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/25 18:10:52 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*to_ps_two(char cmd, char *value)
{
	static char	*ps_two = "> ";

	if (cmd == 's')
		ps_two = value;
	return (ps_two);
}
