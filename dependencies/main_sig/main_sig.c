/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:33:24 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/11 14:40:02 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sig.h"

void	main_signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		printf("Handling Ctrl-C signal...\n");
	}
	else if (sig == SIGQUIT)
	{
		rl_replace_line("", 0);
		printf("Handling Ctrl-D signal...\n");
	}
	rl_on_new_line();
	rl_redisplay();
}

void	setup_main_signals(void)
{
	signal(SIGINT, main_signal_handler);
	signal(SIGQUIT, main_signal_handler);
}
