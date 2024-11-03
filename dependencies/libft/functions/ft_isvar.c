/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:35:25 by ballain           #+#    #+#             */
/*   Updated: 2024/11/03 19:40:24 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenvar_name(char *arg)
{
	int	len;

	len = 0;
	if (ft_issvar(*arg))
		return (1);
	if (ft_isvar(arg))
	{
		while (arg && *arg && (ft_isalnum(*arg) || *arg == '_'))
			arg += ((len += 1), 1);
		return (len);
	}
	return (0);
}

int	ft_issvar(char c)
{
	if (c == '!')
		return (1);
	if (c == '?')
		return (1);
	if (c == '*')
		return (1);
	if (c == '#')
		return (1);
	if (c == '_')
		return (1);
	if (c == '@')
		return (1);
	if (c == '$')
		return (1);
	if (ft_isdigit(c))
		return (1);
	return (0);
}

int	ft_isvar(char *str)
{
	if (!str)
		return (0);
	if (ft_issvar(*str) || ft_isalpha(*str))
		return (1);
	return (0);
}
