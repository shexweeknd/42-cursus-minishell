/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:26:35 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/25 16:52:50 by ballain          ###   ########.fr       */
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
	free(*(env->path));
	free(env->path);
	free(env);
}
