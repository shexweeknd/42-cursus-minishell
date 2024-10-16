/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:20:11 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/16 15:46:45 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_static.h"

static unsigned char	_sig(int new_sig, int change)
{
	static unsigned char	sig = 0;

	if (change)
		sig = new_sig;
	return (sig);
}

unsigned char	get_sig(void)
{
	return (_sig(0, 0));
}

void	set_sig(unsigned char new_sig)
{
	_sig(new_sig, 1);
}
