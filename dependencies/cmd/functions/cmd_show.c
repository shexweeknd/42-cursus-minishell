/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 02:47:59 by ballain           #+#    #+#             */
/*   Updated: 2024/08/19 10:25:02 by ballain          ###   ########.fr       */
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

void	ft_show_redirect(char *label, t_list *r_arg)
{
	t_list	*tmp;

	tmp = r_arg;
	while (tmp)
	{
		printf("%s	: [%s]\n", label, (char *)tmp->content);
		tmp = tmp->next;
	}
}

void	ft_show_cmd(t_cmd *cmd)
{
	int		i;

	printf("\033[0;4;32mCMD	:\033[0;0m\n");
	while (cmd)
	{
		i = 0;
		while (cmd->args && cmd->args[i])
			printf(" ARGS	: [%s]\n", cmd->args[i++]);
		if (cmd->file_in)
			ft_show_redirect(" REDIRECTION [IN]", cmd->file_in);
		if (cmd->heredoc)
			ft_show_redirect(" REDIRECTION [HEREDOC]", cmd->heredoc);
		if (cmd->file_out)
			ft_show_redirect(" REDIRECTION [OUT]", cmd->file_out);
		if (cmd->file_append)
			ft_show_redirect(" REDIRECTION [APPEND]", cmd->file_append);
		ft_show_ltype(cmd->link_type);
		printf("\n");
		cmd = cmd->next;
	}
}
