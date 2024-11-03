/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:14:57 by hramaros          #+#    #+#             */
/*   Updated: 2024/11/03 18:50:57 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_simple_add(char *dest, char **arg, int i)
{
	int	len;

	i += ft_add_char(dest, **arg, i);
	len = 1;
	while (++(*arg) && **arg != '\'')
		i += ((len += 1), ft_add_char(dest, **arg, i));
	if (*arg && **arg == '\'')
	{
		i += ((len += 1), ft_add_char(dest, **arg, i));
		return ((*arg += 1), len);
	}
	return (len);
}

int	ft_default_add(char *dest, char **arg, char end, int i)
{
	int	len;
	int	len_var;

	len = 0;
	while (*arg && **arg && ((end == 0 && !ft_is_quote(**arg)) || \
		(end == '"' && **arg != '"')))
	{
		if (**arg == '$' && (*arg)++)
		{
			len_var = ft_lenvar_name(*arg);
			if (*arg && **arg == '\'' && end == '"')
				len += (ft_add_char(dest, '$', i + len), 1);
			if (*arg && **arg == '\'')
				len += ft_simple_add(dest, arg, i + len);
			else if (!ft_isvar(*arg) && (!ft_is_quote(**arg) || end == '"'))
				len += (ft_add_char(dest, '$', i + len), 1);
			else
				len += ft_add_var(dest, *arg, len_var, i + len);
			*arg += len_var;
		}
		else
			*arg += ((len += (ft_add_char(dest, **arg, i + len), 1)), 1);
	}
	return (len);
}

int	ft_manage_arg_content(char *dest, char *arg)
{
	int	len;

	len = 0;
	while (arg && *arg)
	{
		if (*arg == '\'')
			len += ft_simple_add(dest, &arg, len);
		else if (*arg == '"')
		{
			len += (ft_add_char(dest, *(arg++), len), 1);
			len += ft_default_add(dest, &arg, '"', len);
			if (arg && *arg == '"')
				len += (ft_add_char(dest, *(arg++), len), 1);
		}
		else
			len += ft_default_add(dest, &arg, 0, len);
	}
	return (len);
}

int	ft_manage_args(t_cmd *cmd)
{
	if (get_status() == 13)
		set_status(0);
	cmd->nb_arg = ft_update_args(cmd);
	if (cmd->args[0] && !ft_strcmp(cmd->args[0], "."))
	{
		ft_perror_fd(2, (char *[]){MSH_LOG, ": ", cmd->args[0], ": ", \
		"filename argument required\n", cmd->args[0], ": usage: ", \
		cmd->args[0], " filename[arguments]", NULL});
		return (2);
	}
	if (!ft_manage_rfile(cmd->file_in) || \
		!ft_manage_rfile(cmd->file_out))
		return (1);
	return (-1);
}
