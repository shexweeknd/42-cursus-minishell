/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:22:44 by ballain           #+#    #+#             */
/*   Updated: 2024/09/25 18:22:47 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig.h"

void	to_stdin(char cmd)
{
	static int	fd = 0;

	if (cmd == 'c')
	{
		fd = dup(STDIN_FILENO);
		close(STDIN_FILENO);
	}
	else if (cmd == 'o')
		(dup(fd), close(fd));
}

int	sig_type(char cmd, int value)
{
	static int	sig_type = 0;

	if (cmd == 'g')
		return (sig_type);
	else if (cmd == 's')
		return (sig_type = value, sig_type);
	else if (cmd == 'r')
		return (sig_type = 0, sig_type);
	return (sig_type);
}

void	sec_sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		to_stdin('c');
		printf("\n\e[K");
	}
	rl_on_new_line();
	rl_replace_line("\e[K", 0);
	sig_type('s', signal);
	sec_prompt_flag('s', 1);
	set_status(130);
}