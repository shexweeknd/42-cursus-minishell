/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_checker_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:31:42 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/28 14:32:00 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

char	*subst_home(char *src, t_env *env)
{
	char	*tmp;
	char	*result;
	char	*home;

	if (!*src || *src != '~')
		return (src);
	if (!src[1])
		return (free(src), ft_strdup(ft_getvar(env, "HOME")));
	else if (src[1] != '/')
		return (src);
	home = ft_getvar(env, "HOME");
	tmp = ft_substr(src, 1, ft_strlen(src));
	result = ft_strjoin(home, tmp);
	return (free(tmp), result);
}
