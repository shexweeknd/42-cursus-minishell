/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:26:35 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/27 12:01:41 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	ft_getlen_path(char *path)
{
	int	len;

	if (!path)
		return (0);
	len = 1;
	while (*path)
	{
		while (*path && *path != ':')
			path++;
		if (*path == ':' && path++ && *path)
			len++;
	}
	return (len);
}

void	ft_free_env(t_env *env)
{
	int	i;

	i = 0;
	while (env->var[i])
		free(env->var[i++]);
	free(env->var);
	if (env->path)
		free(*(env->path));
	free(env->path);
	free(env);
}
