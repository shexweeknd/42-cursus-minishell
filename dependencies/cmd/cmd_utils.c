/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:11:02 by ballain           #+#    #+#             */
/*   Updated: 2024/08/15 12:37:52 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	ft_show_ltype(t_link link_type)
{
	if (link_type == BG)
		printf(" l_type	: [BG]\n");
	if (link_type == NONE)
		printf(" l_type	: [NONE]\n");
	if (link_type == PIPE)
		printf(" l_type	: [PIPE]\n");
	if (link_type == OR)
		printf(" l_type	: [OR]\n");
	if (link_type == AND)
		printf(" l_type	: [AND]]\n");
}

void	ft_show_redirection(t_redirect redirect)
{
	if (redirect == IN_1)
		printf(" REDIRECTION	: [IN]\n");
	else if (redirect == IN_2)
		printf(" REDIRECTION	: [HEREDOC]\n");
	else if (redirect == OUT_1)
		printf(" REDIRECTION	: [OUT]\n");
	else
		printf(" REDIRECTION	: [OUT END]\n");
}

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

	tmp = cmd;
	if (!cmd)
		return (0);
	cmd += _get_info(&_cmd->name, cmd);
	if (*cmd == '-')
		cmd += _get_info(&_cmd->option, cmd);
	cmd += _get_info(&_cmd->arg, cmd);
	if (*cmd && !ft_is_delimiter(*cmd) && !ft_is_redirect(*cmd))
		*(--cmd) = '<';
	return (cmd - tmp);
}
