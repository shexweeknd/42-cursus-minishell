/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:57:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/07 09:27:19 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_err.h"

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
