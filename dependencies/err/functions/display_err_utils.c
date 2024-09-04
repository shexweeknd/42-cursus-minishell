/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_err_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:46:07 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/04 11:38:24 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/m_err.h"

char	*get_link_char(t_link link)
{
	if (link == PIPE)
		return ("|");
	else if (link == BG)
		return ("&");
	else if (link == OR)
		return ("||");
	else if (link == AND)
		return ("&&");
	else
		return ("");
}
