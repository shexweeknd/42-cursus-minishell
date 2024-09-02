/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:25:21 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/02 15:52:29 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uniform.h"

// TODO va servir a uniformiser les args dans les char ** de la strucutre parsee

char	*uniform_by_dollar(char *arg, t_env_var *venv)
{
	(void)venv;
	return (arg);
}

char	*get_rid_of_dquote(char *arg)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (ft_strlen(arg) - 1));
	if (!result)
		return (arg);
	i = 0;
	while (arg[i + 1])
	{
		result[i] = arg[i + 1];
		i++;
	}
	result[--i] = '\0';
	return (free(arg), result);
}

char	*uniform_by_dquote(char *arg, t_env_var *venv)
{
	if (ft_get_occ(arg, '"') <= 1)
		return (arg);
	// if dquote detected and dollar inside dquote then uniform by dollar else don't do anything
	arg = get_rid_of_dquote(arg);
	arg = uniform_by_dollar(arg, venv);
	return (arg);
}

char	*uniform_by_squote(char *arg, t_env_var *venv)
{
	(void)venv;
	return (arg);
}

void	uniform_args(char **args, int end, t_env_var *venv)
{
	int	i;

	i = 1;
	while (i <= end)
	{
		args[i] = uniform_by_dquote(args[i], venv);
		args[i] = uniform_by_squote(args[i], venv);
		i++;
	}
}

t_cmd	*uniform_cmds(t_cmd *cmds, t_env_var *venv)
{
	t_cmd	*backup;

	backup = cmds;
	while (cmds)
	{
		uniform_args(cmds->args, cmds->nb_arg, venv);
		cmds = cmds->next;
	}
	return (backup);
}
