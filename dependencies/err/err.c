/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:57:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/15 09:39:50 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_err.h"

int	check_syntax_err(char *prompt, int with_hd)
{
	int	flag;

	flag = 0;
	if (is_only_spaces(prompt))
		flag = 1;
	if (_hd_occ(prompt) && with_hd)
		flag = hd_check_syntax_err(prompt);
	else if (!flag && is_unexpected(prompt, 0))
		flag = 1;
	if (!flag && is_unexpected(prompt, 1))
		flag = 1;
	if (flag)
		set_status(2);
	return (flag);
}
