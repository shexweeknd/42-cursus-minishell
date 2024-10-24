/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:11:21 by ballain           #+#    #+#             */
/*   Updated: 2024/10/24 13:27:18 by hramaros         ###   ########.fr       */
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

int	ft_exit_status(int status)
{
	if (!WIFEXITED(status))
	{
		if (get_sig() == SIGINT)
			printf("\n");
		else if (get_sig() == SIGQUIT)
		{
			printf("\e[K");
			if (isatty(STDIN_FILENO))
				printf("Quit (core dumped)\n");
		}
	}
	if (set_sig(0), WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			printf("Segmentation fault (core dumped)\n");
		if (WTERMSIG(status) == SIGINT)
			return (130);
		if (WTERMSIG(status) == SIGQUIT)
			return (131);
	}
	return (WEXITSTATUS(status));
}
