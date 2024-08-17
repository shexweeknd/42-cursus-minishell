/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:11:28 by ballain           #+#    #+#             */
/*   Updated: 2024/08/16 22:51:31 by ballain          ###   ########.fr       */
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

int	ft_is_quote(const char c)
{
	if (c == '"' || c == '\'')
		return (c);
	return (0);
}
