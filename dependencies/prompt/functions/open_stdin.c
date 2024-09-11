/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:15:57 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/11 14:16:07 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	re_open_stdin(void)
{
	int	new_stdin;

	new_stdin = open("/dev/tty", O_RDONLY);
	if (new_stdin == -1)
		perror("Failed to reopen STDIN");
}
