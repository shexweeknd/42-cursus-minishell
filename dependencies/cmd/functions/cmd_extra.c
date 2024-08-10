/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:10:28 by ballain           #+#    #+#             */
/*   Updated: 2024/08/10 05:45:13 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

t_redirect	ft_get_rtype(char *cmd)
{
	if (!cmd)
		return (NO);
	if (*cmd == '<' && cmd++)
	{
		if (*cmd == '<')
			return (IN_2);
		return (IN_1);
	}
	if (*cmd == '>' && cmd++)
	{
		if (*cmd == '>')
			return (OUT_2);
		return (OUT_1);
	}
	return (NO);
}

int	ft_get_redirect(t_cmd *_cmd, char *cmd)
{
	char		*tmp;
	t_io_arg	*new_io_arg;

	if (!cmd)
		return (0);
	tmp = cmd;
	if (ft_is_redirect(*cmd))
	{
		new_io_arg = (t_io_arg *)malloc(sizeof(t_io_arg));
		if (!new_io_arg)
			return (0);
		new_io_arg->redirect = ft_get_rtype(cmd);
		while (ft_isspace(*cmd) || ft_is_redirect(*cmd))
			cmd++;
		if (new_io_arg->redirect != NO)
			cmd += _get_info(&new_io_arg->arg, cmd);
		ft_add_back_((void **)&_cmd->io_arg, new_io_arg, IO_ARG);
		return (cmd - tmp);
	}
	return (0);
}

t_link	ft_get_ltype(char *cmd)
{
	if (!cmd)
		return (NONE);
	if (*cmd == '|' && cmd++)
	{
		if (cmd && *cmd == '|')
			return (OR);
		return (PIPE);
	}
	if (*cmd == '&' && cmd++)
	{
		if (cmd && *cmd == '&')
			return (AND);
		return (BG);
	}
	return (NONE);
}
