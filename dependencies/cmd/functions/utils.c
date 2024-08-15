/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:11:28 by ballain           #+#    #+#             */
/*   Updated: 2024/08/15 13:32:04 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int	ft_is_delimiter(const char c)
{
	return (c == '|' || c == '&');
}

int	ft_is_cmd_sep(const char c)
{
	return (ft_isspace(c) || ft_is_delimiter(c));
}

int	ft_is_redirect(const char c)
{
	return (c == '<' || c == '>');
}
