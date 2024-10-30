/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_until.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 07:26:21 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/30 09:19:49 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	skip_until(char *prompt, char offset)
{
	int	result;

	result = 1;
	if (!prompt || !prompt[result])
		return (0);
	while (prompt[result])
	{
		if (prompt[result++] == offset)
			break ;
		if (!prompt[result])
			return (1);
	}
	return (result);
}
