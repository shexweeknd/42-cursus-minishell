/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:10:28 by ballain           #+#    #+#             */
/*   Updated: 2024/08/19 10:46:46 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

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
	t_list		*l_new;
	t_redirect	redirect_type;

	if (!cmd)
		return (0);
	tmp = cmd;
	if (ft_is_redirect(*cmd))
	{
		redirect_type = ft_get_rtype(cmd);
		l_new = ft_lstnew(NULL);
		while (ft_isspace(*cmd) || ft_is_redirect(*cmd))
			cmd++;
		cmd += _get_info((char **)&l_new->content, cmd);
		if (redirect_type == IN_1)
			ft_add_back_((void **)&_cmd->file_in, l_new, (t_lst_utils){0});
		if (redirect_type == IN_2)
			ft_add_back_((void **)&_cmd->heredoc, l_new, (t_lst_utils){0});
		if (redirect_type == OUT_1)
			ft_add_back_((void **)&_cmd->file_out, l_new, (t_lst_utils){0});
		if (redirect_type == OUT_2)
			ft_add_back_((void **)&_cmd->file_append, l_new, (t_lst_utils){0});
		return (cmd - tmp);
	}
	return (0);
}
