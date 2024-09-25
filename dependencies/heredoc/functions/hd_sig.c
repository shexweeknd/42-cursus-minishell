/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 08:43:22 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/25 09:20:26 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

void	hd_prompt_sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		to_stdin('c');
		printf("\n\e[K");
	}
	rl_on_new_line();
	rl_replace_line("\e[K", 0);
	set_status(130);
}
