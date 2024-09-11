/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:04:01 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/11 14:04:13 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	print_prompt(t_prompt *prompt)
{
	printf("\n");
	printf("Waitnl: %d\n", prompt->wait_nl);
	printf("To_exit: %d\n", prompt->to_exit);
	printf("To_execute: %d\n", prompt->to_execute);
	printf("is_eof: %d\n", prompt->is_eof);
}
