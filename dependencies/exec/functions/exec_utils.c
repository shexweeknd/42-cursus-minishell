/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:13:56 by ballain           #+#    #+#             */
/*   Updated: 2024/09/04 20:50:56 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

char	*ft_join_path(char *path, char *sep, char *name)
{
	int		i;
	int		len;
	char	*r_value;

	if (!path)
		path = ".";
	if (!sep)
		sep = "/";
	if (!name)
		return (NULL);
	i = 0;
	len = ft_strlen(path) + ft_strlen(path) + ft_strlen(path) + 1;
	r_value = (char *)malloc(sizeof(char) * len);
	if (!r_value)
		return (NULL);
	while (*path)
		r_value[i++] = *(path++);
	while (*sep)
		r_value[i++] = *(sep++);
	while (*name)
		r_value[i++] = *(name++);
	r_value[i] = '\0';
	return (r_value);
}

char	*ft_search_executable(t_env *env, char *exe_name)
{
	char	*tmp;
	int		i;

	i = 0;
	if (access(exe_name, F_OK | X_OK) == 0)
		return (exe_name);
	if (!env->path)
		return (NULL);
	while (env->path[i])
	{
		tmp = ft_join_path(env->path[i++], "/", exe_name);
		if (!tmp)
			return (NULL);
		if (access(tmp, F_OK | X_OK) == 0)
			return (tmp);
		free(tmp);
	}
	return (NULL);
}
