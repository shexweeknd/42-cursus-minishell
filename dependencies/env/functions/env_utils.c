/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:26:35 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/28 15:57:05 by ballain          ###   ########.fr       */
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
	while (env && env->var && env->var[i])
		free(env->var[i++]);
	if (env && env->var)
		free(env->var);
	if (env->path)
		free(*(env->path));
	if (env && env->path)
		free(env->path);
	if (env)
		free(env);
}
