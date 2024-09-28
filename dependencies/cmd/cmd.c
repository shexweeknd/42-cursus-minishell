/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:10:50 by ballain           #+#    #+#             */
/*   Updated: 2024/09/28 15:54:05 by ballain          ###   ########.fr       */
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
		cmd += (_cmd->args[i] = NULL, _get_info(&_cmd->args[i++], cmd));
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
	r_cmd->l_type = ft_get_ltype(cmd);
	r_cmd->next = NULL;
	return (r_cmd);
}

t_cmd	*ft_get_cmds(char *cmd)
{
	t_cmd		*cmds;
	t_cmd		*tmp;
	t_lst_utils	actions;
	int			i;
	int			len;

	if (!cmd)
		return (NULL);
	actions = (t_lst_utils){CMD, _add_next_cmd, _next_cmd};
	cmds = NULL;
	while (*cmd)
	{
		tmp = ft_init_cmd(cmd);
		ft_add_back_((void **)(&cmds), tmp, actions);
		i = ((len = 0), 0);
		while (tmp && tmp->args && tmp->args[i])
			len += ft_strlen(tmp->args[i++]);
		cmd += len;
		while (*cmd && !ft_is_delimiter(*cmd))
			cmd++;
		while (*cmd && ft_is_delimiter(*cmd))
			cmd++;
	}
	hd_cmd('f', NULL);
	return (cmds);
}
