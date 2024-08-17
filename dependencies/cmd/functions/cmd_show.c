/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 02:47:59 by ballain           #+#    #+#             */
/*   Updated: 2024/08/17 02:48:00 by ballain          ###   ########.fr       */
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

void	ft_show_cmd(t_cmd *cmd)
{
	t_io_arg	*tmp;
	int			i;

	printf("\033[0;4;32mCMD	:\033[0;0m\n");
	while (cmd)
	{
		i = 0;
		while (cmd->args && cmd->args[i])
			printf(" ARGS	: [%s]\n", cmd->args[i++]);
		ft_show_ltype(cmd->link_type);
		if (!cmd->io_arg)
			printf(" NO REDIRECTION\n");
		else
		{
			tmp = cmd->io_arg;
			while (tmp)
			{
				ft_show_redirection(tmp->redirect);
				printf(" ARG	: [%s]\n", tmp->arg);
				tmp = tmp->next;
			}
		}
		printf("\n");
		cmd = cmd->next;
	}
}
