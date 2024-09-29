/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:33:24 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/29 12:11:13 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig.h"

int	sec_prompt_flag(char cmd, int value)
{
	static int	result = 0;

	if (cmd == 'g')
		return (result);
	else if (cmd == 's')
		return (result = value, result);
	else if (cmd == 'r')
		return (result = 0, result);
	return (result);
}

void	main_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		if (!sec_prompt_flag('g', 0))
			printf("\n\e[K");
		printf("\e[K");
	}
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	set_status(130);
}

void	child_signal_handler(int sig)
{
	if (sig == SIGINT)
		printf("\n");
	else if (sig == SIGQUIT)
	{
		printf("\e[K");
		printf("Quit (core dumped)\n");
	}
}

void	setup_main_signals(void)
{
	signal(SIGINT, main_sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	setup_child_signals(void)
{
	signal(SIGINT, child_signal_handler);
	signal(SIGQUIT, child_signal_handler);
}
