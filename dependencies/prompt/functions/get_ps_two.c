/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ps_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:36:00 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/07 11:36:20 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

// TODO DEBUG FT_GETVAR
char	*get_col_ps_two(t_env *env)
{
	char	*ps_two;
	char	*tmp;
	char	*result;

	ps_two = ft_getvar(env, "PS2");
	if (!ps_two)
		return (">");
	tmp = ft_strjoin("\033[0;32m", ps_two);
	result = ft_strjoin(tmp, "\033[0;0m ");
	return (free(tmp), result);
}
