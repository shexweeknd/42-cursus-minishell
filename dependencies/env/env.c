/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:22:05 by ballain           #+#    #+#             */
/*   Updated: 2024/09/24 09:07:14 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*ft_search_var(t_env *env, char *var_name)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(var_name);
	while (env->var[++i])
	{
		if (ft_strncmp(env->var[i], var_name, len) == 0
			&& env->var[i][len] == '=')
			break ;
	}
	return (env->var[i]);
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
	env->var = (char **)malloc(sizeof(char *) * (ft_getlen_strtab(envp) + 1));
	if (!env->var)
		return (NULL);
	path = getenv("PATH");
	while (*envp)
		env->var[i++] = ft_strdup(*(envp++));
	env->var[i] = 0;
	env->path = ft_split_path(path);
	return (env);
}

char	*ft_getvar(t_env *env, char *var_name)
{
	int		i;
	char	*var;

	i = 0;
	var = ft_search_var(env, var_name);
	if (var)
	{
		while (var[i++] != '=')
			;
		if (*(var + i))
			return (var + i);
	}
	return (NULL);
}

char	*ft_setvar(t_env *env, char *var_name, char *str)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(var_name);
	while (env->var[++i])
	{
		if (ft_strncmp(env->var[i], var_name, len) == 0
			&& env->var[i][len] == '=')
		{
			env->var[i] = (free(env->var[i]), ft_strdup(str));
			if (ft_strcmp(var_name, "PATH") == 0)
			{
				(free(*env->path), free(env->path));
				env->path = ft_split_path((env->var[i]));
			}
			return (env->var[i]);
		}
	}
	return (NULL);
}
