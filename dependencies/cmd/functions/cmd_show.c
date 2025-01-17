/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 02:47:59 by ballain           #+#    #+#             */
/*   Updated: 2024/09/11 16:10:28 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	ft_show_ltype(t_link l_type)
{
	if (l_type == BG)
		printf(" l_type	: [BG]\n");
	if (l_type == NONE)
		printf(" l_type	: [NONE]\n");
	if (l_type == PIPE)
		printf(" l_type	: [PIPE]\n");
	if (l_type == OR)
		printf(" l_type	: [OR]\n");
	if (l_type == AND)
		printf(" l_type	: [AND]\n");
}

void	ft_show_redirect(char *label, t_rfile *r_arg)
{
	t_rfile	*tmp;

	tmp = r_arg;
	while (tmp)
	{
		if (tmp->option == O_RDONLY)
			printf("%s	[IN] or [HEREDOC] : [%s]\n", label, tmp->args);
		else if (tmp->option == (O_TRUNC | O_WRONLY | O_CREAT))
			printf("%s	[OUT] : [%s]\n", label, tmp->args);
		else
			printf("%s	[APPEND] : [%s]\n", label, tmp->args);
		tmp = tmp->next;
	}
}

void	ft_show_cmd(t_cmd *cmd)
{
	int	i;

	printf("\033[0;4;32mCMD	:\033[0;0m\n");
	while (cmd)
	{
		i = 0;
		while (cmd->args && cmd->args[i])
			printf(" ARGS	: [%s]\n", cmd->args[i++]);
		printf(" ARGS_NBR: [%d]\n", cmd->nb_arg);
		if (cmd->file_in)
			ft_show_redirect(" REDIRECTION ", cmd->file_in);
		if (cmd->file_out)
			ft_show_redirect(" REDIRECTION ", cmd->file_out);
		ft_show_ltype(cmd->l_type);
		printf("\n");
		cmd = cmd->next;
	}
}
