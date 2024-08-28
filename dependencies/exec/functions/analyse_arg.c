/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:13:03 by ballain           #+#    #+#             */
/*   Updated: 2024/08/28 12:28:34 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

static char	*ft_init_new_arg(char *arg, t_env_var *venv, int len)
{
	int			i;
	char		*r_value;

	i = 0;
	r_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!r_value)
		return (NULL);
	while (*arg)
	{
		while (*arg && *arg != '$')
			r_value[i++] = *(arg++);
		if (*arg && *arg == '$' && arg++)
		{
			len = _skip_venv(arg);
			i += ft_manage_venv(r_value + i, arg, venv, len);
			arg += len;
		}
	}
	r_value[i] = 0;
	return (r_value);
}

static char	*ft_analyse_arg(char *arg, t_env_var *venv)
{
	char	*tmp;

	tmp = NULL;
	if (!arg)
		return (NULL);
	if (*arg && *arg == '\'')
		return (ft_strtrim(arg, "'"));
	if (*arg && (*arg == '$' || *arg == '"'))
	{
		tmp = ft_strtrim(arg, "\"");
		arg = ft_init_new_arg(tmp, venv, ft_new_arg_len(tmp, venv));
		return (free(tmp), arg);
	}
	return (arg);
}

int	ft_analyse_args(t_cmd *cmd, t_env_var *venv)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = NULL;
	while (i < cmd->nb_arg)
	{
		tmp = ft_analyse_arg(cmd->args[i], venv);
		if (tmp != cmd->args[i])
		{
			free(cmd->args[i]);
			cmd->args[i] = tmp;
		}
		i++;
	}
	return (1);
}
