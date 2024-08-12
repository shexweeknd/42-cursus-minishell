/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:11:02 by ballain           #+#    #+#             */
/*   Updated: 2024/08/12 15:34:31 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int	ft_get_info_len(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return (0);
	while (*cmd)
	{
		if (ft_is_cmd_sep(*cmd) || ft_is_redirect(*cmd))
			return (i);
		i++;
		cmd++;
	}
	return (i);
}

int	_get_info(char **str, char *cmd)
{
	int	len;
	int	i;

	if (!cmd || !(*cmd))
		return (0);
	i = _skip_space(cmd);
	len = ft_get_info_len(cmd + i);
	if (len && *str == NULL)
		*str = ft_substr(cmd + i, 0, len);
	i += _skip_space(cmd + i + len);
	return (i + len);
}

int	ft_get_cmd_info(t_cmd *_cmd, char *cmd)
{
	char		*tmp;
	t_io_arg	*io_tmp;

	tmp = cmd;
	if (!cmd)
		return (0);
	cmd += _get_info(&_cmd->name, cmd);
	if (*cmd == '-')
		cmd += _get_info(&_cmd->option, cmd);
	cmd += _get_info(&_cmd->arg, cmd);
	if (*cmd && !ft_is_delimiter(*cmd))
	{
		io_tmp = _init_io_arg(IN_1, NULL);
		cmd += _get_info(&io_tmp->arg, cmd);
		ft_add_back_((void **)&_cmd->io_arg, io_tmp, IO_ARG);
	}
	return (cmd - tmp);
}
