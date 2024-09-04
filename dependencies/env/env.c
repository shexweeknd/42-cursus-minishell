/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:22:05 by ballain           #+#    #+#             */
/*   Updated: 2024/09/04 20:17:12 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	ft_getlen_env(char **envp)
{
	int	len;

	len = 0;
	while (*envp)
		(len++, envp++);
	return (len);
}

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

char	**ft_split_path(char *src)
{
	char	**r_value;
	char	*tmp;
	int		i;

	i = 0;
	r_value = (char **)malloc(sizeof(char *) * (ft_getlen_path(src) + 1));
	if (!r_value)
		return (NULL);
	tmp = ft_strdup(src);
	while (*tmp)
	{
		r_value[i++] = tmp;
		while (*tmp && *tmp != ':')
			tmp++;
		if (*tmp && *tmp == ':')
			*(tmp++) = 0;
	}
	r_value[i] = NULL;
	return (r_value);
}

t_env	*ft_getenv(char **envp)
{
	t_env	*env;
	char	*path;
	int		i;

	i = 0;
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->var = (char **)malloc(sizeof(char *) * (ft_getlen_env(envp) + 1));
	if (!env->var)
		return (NULL);
	path = getenv("PATH");
	while (*envp)
		env->var[i++] = ft_strdup(*(envp++));
	env->path = ft_split_path(path);
	free(path);
	return (env);
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
