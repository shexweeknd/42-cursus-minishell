/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:17:17 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/24 12:08:22 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_parent_path(char *path, int index, int count)
{
	while (index >= 0 && count != 0)
	{
		if (path[index] == '/')
			count--;
		path[index] = 0;
		if (count)
			index--;
	}
	if (index < 0)
		index = 0;
	return (index);
}

char	*ft_setpath(char *arg)
{
	int		i;
	int		j;
	int		count;
	char	*cp;

	count = ((i = 0), (j = 0), ft_strlen(arg));
	cp = (char *)malloc(sizeof(char) * (count + 1));
	if (!cp)
		return (NULL);
	ft_bzero(cp, count + 1);
	while (arg[i])
	{
		while (arg[i] && arg[i] != '/')
			cp[j++] = arg[i++];
		if (arg[i] && arg[i] == '/')
			cp[j++] = arg[i++];
		if (arg[i] == '.')
		{
			count = 1;
			if (ft_strncmp(arg + i, "..", 2) == 0)
				count = 2;
			j = ((i += count), ft_parent_path(cp, j, count));
		}
	}
	return (cp);
}

char	*ft_getpath(t_executable exec, char *home_path, char *old_path)
{
	char	*path;

	if (ft_getlen_strtab(exec.cmd->args) > 2)
		return (printf("minishell: cd: trop d'arguments\n"), NULL);
	else if (!exec.cmd->args[1] || \
			(exec.cmd->args[1] && *exec.cmd->args[1] == '~'))
	{
		if (!home_path)
			path = ((printf("minishell: cd : « HOME » non défini\n"), NULL));
		else if (exec.cmd->args[1])
			path = ft_str_replace(exec.cmd->args[1], "~", home_path, 0);
		else
			path = ft_strdup(home_path);
	}
	else if (!ft_strcmp(exec.cmd->args[1], "-"))
	{
		if (!old_path)
			path = ((printf("minishell: cd : « OLDPWD » non défini\n"), NULL));
		else
			path = ft_strdup(old_path);
	}
	else
		path = ft_strdup(exec.cmd->args[1]);
	return (path);
}

void	ft_save_path(t_env *env, char *path)
{
	char	*tmp;
	char	*cur_path;

	cur_path = ft_getvar(env, "PWD");
	tmp = ft_strjoin("OLDPWD=", cur_path);
	(ft_setvar(env, "OLDPWD", tmp), free(tmp));
	if (*path != '/')
	{
		if (path[ft_strlen(path) - 1] == '/')
			path[ft_strlen(path) - 1] = 0;
		tmp = ft_join((char *[]){cur_path, "/", path, NULL});
	}
	else
		tmp = ft_strdup(path);
	path = (free(path), ft_setpath(tmp));
	if (!ft_strlen(path))
		path[0] = '/';
	tmp = (free(tmp), ft_strjoin("PWD=", path));
	(ft_setvar(env, "PWD", tmp), free(tmp), free(path));
}

int	cd(t_executable exec)
{
	char	*path;
	char	*old_path;
	char	*home_path;

	home_path = ft_getvar(exec.env, "HOME");
	old_path = ft_getvar(exec.env, "OLDPWD");
	path = ft_getpath(exec, home_path, old_path);
	if (path)
	{
		if (chdir(path) == -1)
		{
			printf("minishell: cd: %s: %s\n", path, strerror(errno));
			free(path);
		}
		else
			ft_save_path(exec.env, path);
		return (0);
	}
	return (1);
}
