/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:17:11 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/19 08:52:50 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

char	*ft_getvar_name(char *arg)
{
	char	*equal;

	equal = ft_strchr(arg, '=');
	if (equal)
		return (ft_substr(arg, 0, equal - arg));
	return (NULL);
}

int	ft_new_env(t_env *env, char *new)
{
	int		i;
	char	**new_varenv;

	if (!ft_strchr(new, '='))
		return (1);
	i = -1;
	new_varenv = (char **)malloc(sizeof(char *) * (ft_getlen_strtab(env->var) + 2));
	if (!new_varenv)
		return (1);
	while (env->var[++i])
		new_varenv[i] = env->var[i];
	new_varenv[i++] = new;
	new_varenv[i] = NULL;
	env->var = (free(env->var), new_varenv);
	return (0);
}

void	ft_sort_tab(char **tab)
{
	int		i;
	int		len;
	int		count;
	char	*tmp;

	count = 0;
	len = ft_getlen_strtab(tab);
	while (1)
	{
		i = 0;
		if (tab[i] && tab[i + 1])
		{
			if (strcmp(tab[i], tab[i + 1]) > 0)
				tab[i + 1] = ((tmp = tab[i]), (tab[i] = tab[i + 1]), tmp);
			else
				count++;
		}
		else
			count++;
		i++;
		if (count == len)
			break;
		if (!tab[i])
			i = 0;	
	}
}

int	ft_export_no_arg(char **env)
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
		cp_env[i] = ft_strdup(env[i]);
	cp_env[i] = 0;
	return (0);

}

void	export(t_executable exec)
{
	int		i;
	int		len;
	char	*var_name;

	if (!exec.cmd->args[1])
		return ;
	i = -1;
	var_name = ft_getvar_name(exec.cmd->args[1]);
	len = ft_strlen(var_name);
	while (exec.env->var[++i])
	{
		if (ft_strncmp(exec.env->var[i], var_name, len) == 0 && \
			exec.env->var[i][len] == '=')
			break ;
	}
	if (exec.env->var[i])
		exec.env->var[i] = (free(exec.env->var[i]), exec.cmd->args[1]);
	else
		ft_new_env(exec.env, exec.cmd->args[1]);
}
