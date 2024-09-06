/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:57:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/06 11:49:53 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cmd/includes/cmd.h"
#include "../cmd/includes/cmd_struct.h"
#include "m_err.h"
#include "m_err_struct.h"

int	is_only_spaces(char *prompt)
{
	prompt += _skip_space(prompt);
	if (!*prompt)
		return (1);
	return (0);
}

int	check_syntax_err(char *prompt)
{
	if (is_only_spaces(prompt))
		return (free(prompt), 1);
	if (is_unexpected(prompt))
		return (free(prompt), 1);
	return (0);
}
