/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:10:50 by ballain           #+#    #+#             */
/*   Updated: 2024/08/12 18:31:52 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	ft_show_cmd(t_cmd *cmd)
{
	t_io_arg	*tmp;
	printf("\033[0;4;32mCMD	:\033[0;0m\n");
	while (cmd)
	{
		printf(" name	: [%s]\n", cmd->name);
		printf(" option	: [%s]\n", cmd->option);
		printf(" arg	: [%s]\n", cmd->arg);
		if (cmd->link_type == BG)
			printf(" l_type	: [BG]\n");
		if (cmd->link_type == NONE)
			printf(" l_type	: [NONE]\n");
		if (cmd->link_type == PIPE)
			printf(" l_type	: [PIPE]\n");
		if (cmd->link_type == OR)
			printf(" l_type	: [OR]\n");
		if (cmd->link_type == AND)
			printf(" l_type	: [AND]]\n");
		if (!cmd->io_arg)
			printf(" NO REDIRECTION\n");
		else
		{
			tmp = cmd->io_arg;
			while (tmp)
			{
				if (tmp->redirect == IN_1)
					printf(" REDIRECTION	: [IN]\n");
				else if (tmp->redirect == IN_2)
					printf(" REDIRECTION	: [HEREDOC]\n");
				else if (tmp->redirect == OUT_1)
					printf(" REDIRECTION	: [OUT]\n");
				else
					printf(" REDIRECTION	: [OUT END]\n");
				printf(" ARG	: [%s]\n", tmp->arg);
				tmp = tmp->next;
			}
		}
		printf("\n");
		cmd = cmd->next;
	}
}

t_cmd	*ft_init_cmd(char *cmd)
{
	t_cmd	*r_cmd;

	if (!cmd)
		return (NULL);
	while (*cmd && ft_isspace(*cmd))
		cmd++;
	r_cmd = _init_cmd();
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
	t_cmd	*cmds;

	cmds = NULL;
	while (*cmd)
	{
		ft_add_back_((void **)(&cmds), (void *)ft_init_cmd(cmd), CMD);
		while (*cmd && !ft_is_delimiter(*cmd))
			cmd++;
		while (*cmd && ft_is_delimiter(*cmd))
			cmd++;
	}
	// ft_show_cmd(cmds);
	return (cmds);
}
