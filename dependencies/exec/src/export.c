/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:17:11 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/27 13:08:09 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

static void	ft_printsort_tab(char **tab)
{
	int		i;
	int		len;
	int		count;
	char	*tmp;

	len = ((count = ((i = 0), 0)), ft_getlen_strtab(tab));
	while (tab)
	{
		if (tab[i] && tab[i + 1] && ft_strcmp(tab[i], tab[i + 1]) > 0)
			tab[i + 1] = ((tmp = tab[i]), (tab[i] = tab[i + 1]), tmp);
		else
			count++;
		i++;
		if (count == len)
			break ;
		if (!tab[i])
			count = ((i = 0), 0);
	}
	i = 0;
	while (tab && i < len)
		printf("%s\n", tab[i++]);
}

static int	ft_export_no_arg(char **env)
{
	int		i;
	int		len;
	char	**cp_env;

	i = -1;
	len = ft_getlen_strtab(env);
	cp_env = (char **)malloc(sizeof(char *) * (len + 1));
	if (!cp_env)
		return (1);
	while (env[++i])
		cp_env[i] = env[i];
	cp_env[i] = 0;
	return (ft_printsort_tab(cp_env), free(cp_env), 0);
}

static char	*ft_getvar_name(char *arg)
{
	char	*equal;

	equal = ft_strchr(arg, '=');
	if (equal)
		return (ft_substr(arg, 0, equal - arg));
	return (NULL);
}

static int	ft_addenv(t_env *env, char *new)
{
	int		i;
	char	**new_varenv;

	if (!ft_strchr(new, '='))
		return (1);
	i = -1;
	new_varenv = malloc(sizeof(char *) * (ft_getlen_strtab(env->var) + 2));
	if (!new_varenv)
		return (1);
	while (env->var[++i])
		new_varenv[i] = env->var[i];
	new_varenv[i++] = ft_strdup(new);
	new_varenv[i] = NULL;
	env->var = (free(env->var), new_varenv);
	return (0);
}

int	export(t_executable exec)
{
	int		i;
	int		status;
	char	*var_name;

	if (!exec.cmd->args[1])
		return (ft_export_no_arg(exec.env->var));
	status = ((i = 0), i);
	while (exec.cmd->args[++i])
	{
		var_name = ft_getvar_name(exec.cmd->args[i]);
		status = ft_check_valid_var(exec.cmd->args[i], status);
		if (!ft_setvar(exec.env, var_name, exec.cmd->args[i]))
			ft_addenv(exec.env, exec.cmd->args[i]);
		if (!ft_strcmp(var_name, "PATH"))
		{
			if (exec.env->path)
				(free(*exec.env->path), free(exec.env->path));
			exec.env->path = ft_split_path(exec.cmd->args[i]);
		}
		free(var_name);
	}
	return (status);
}
