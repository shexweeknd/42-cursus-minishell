/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:11:21 by ballain           #+#    #+#             */
/*   Updated: 2024/09/28 07:18:23 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_static.h"

static unsigned char	_status(unsigned char new_status, int change)
{
	static unsigned char	value = 0;

	if (change)
		value = new_status;
	return (value);
}

unsigned char	get_status(void)
{
	return (_status(0, 0));
}

void	set_status(unsigned char new_status)
{
	_status(new_status, 1);
}

void	ft_print_status(unsigned char status)
{
	if (WIFSIGNALED(status))
	{
		if (WCOREDUMP(status))
			printf("segmentation fault (core dump)\n");
		else if (WTERMSIG(status) == SIGSEGV)
			printf("segmentation fault\n");
	}
}
