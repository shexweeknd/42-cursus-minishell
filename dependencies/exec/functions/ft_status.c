/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:11:21 by ballain           #+#    #+#             */
/*   Updated: 2024/09/24 11:58:37 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

static int	_status(int new_status, int change)
{
	static int	value = 0;

	if (change)
		value = new_status;
	return (value);
}

int	get_status(void)
{
	return (_status(0, 0));
}

void	set_status(int new_status)
{
	_status(new_status, 1);
}

void	ft_print_status(int status)
{
	if (WIFSIGNALED(status))
	{
		if (WCOREDUMP(status))
			printf("segmentation fault (core dump)\n");
		else if (WTERMSIG(status) == SIGSEGV)
			printf("segmentation fault\n");
	}
	else
		printf("STATUS	: [%d]\n", status);
}
