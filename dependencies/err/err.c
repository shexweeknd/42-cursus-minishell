/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:57:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/23 13:00:12 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_err.h"

/*
int	check_syntax_err(char *prompt)
{
	if (is_only_spaces(prompt))
		return (1);
	if (is_unexpected(prompt))
		return (1);
	return (0);
}*/

int	check_syntax_err(char *prompt)
{
	int flag;

	flag = 0;
	if (is_only_spaces(prompt))
		flag = 1;
	else if (!flag && is_unexpected(prompt, 0))
		flag = 1;
	// process_hd(prompt);
	if (_hd_occ(prompt))
		printf("processing hd...\n");
	if (!flag && is_unexpected(prompt, 1))
		flag = 1;
	return (flag);
}