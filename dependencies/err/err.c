/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:57:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/04 14:58:08 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cmd/includes/cmd.h"
#include "../cmd/includes/cmd_struct.h"
#include "m_err.h"
#include "m_err_struct.h"

int	is_unexpected_token(char *cmd)
{
	if (is_unexpected_at_start(cmd))
		return (1);
	// if (is_unexpected_at_middle(cmd))
	// 	return (1);
	return (0);
}

int	check_syntax_err(char *prompt)
{
	if (is_unexpected_token(prompt))
		return (free(prompt), 1);
	return (0);
}
