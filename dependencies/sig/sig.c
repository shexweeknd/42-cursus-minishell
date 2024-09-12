/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:33:24 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/12 12:07:39 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig.h"

void	main_signal_handler(int sig)
{
	if (sig == SIGINT)
		printf("\n");
	else if (sig == SIGQUIT)
		printf("\e[K");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	child_signal_handler(int sig)
{
	if (sig == SIGINT)
		printf("\n");
	else if (sig == SIGQUIT)
		printf("Quit (core dumped)\n");
}

void	setup_main_signals(void)
{
	signal(SIGINT, main_signal_handler);
	signal(SIGQUIT, main_signal_handler);
}

void	setup_child_signals(void)
{
	signal(SIGINT, child_signal_handler);
	signal(SIGQUIT, child_signal_handler);
}
