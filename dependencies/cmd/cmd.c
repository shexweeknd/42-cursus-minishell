/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:10:50 by ballain           #+#    #+#             */
/*   Updated: 2024/09/02 11:28:53 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static int	ft_get_cmd_info(t_cmd *_cmd, char *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!cmd)
		return (0);
	while (_cmd->args[i])
		i++;
	tmp = cmd;
	while (*cmd && !ft_is_delimiter(*cmd) && !ft_is_redirect(*cmd))
	{
		_cmd->args[i] = NULL;
		cmd += _get_info(&_cmd->args[i++], cmd);
	}
	return (cmd - tmp);
}

static t_cmd	*ft_init_cmd(char *cmd)
{
	t_cmd	*r_cmd;

	if (!cmd)
		return (NULL);
	cmd += _skip_space(cmd);
	r_cmd = _init_cmd(cmd);
	if (!r_cmd)
		return (NULL);
	while (*cmd && !ft_is_delimiter(*cmd))
	{
		if (ft_is_redirect(*cmd))
			cmd += ft_get_redirect(r_cmd, cmd);
		else
			cmd += ft_get_cmd_info(r_cmd, cmd);
	}
	r_cmd->link_type = ft_get_ltype(cmd);
	r_cmd->next = NULL;
	return (r_cmd);
}

t_cmd	*ft_get_cmds(char *cmd)
{
	t_cmd		*cmds;
	t_lst_utils	actions;

	if (!cmd)
		return (NULL);
	actions = (t_lst_utils){CMD, _add_next_cmd, _next_cmd};
	cmds = NULL;
	while (*cmd)
	{
		ft_add_back_((void **)(&cmds), ft_init_cmd(cmd), actions);
		while (*cmd && !ft_is_delimiter(*cmd))
			cmd++;
		while (*cmd && ft_is_delimiter(*cmd))
			cmd++;
	}
	return (cmds);
}
