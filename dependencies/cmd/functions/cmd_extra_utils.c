/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_extra_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:11:10 by ballain           #+#    #+#             */
/*   Updated: 2024/09/25 16:49:53 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

t_rfile	*_init_rfile(t_redirect redirect)
{
	t_rfile	*rfile;

	rfile = (t_rfile *)malloc(sizeof(t_rfile));
	if (!rfile)
		return (NULL);
	if (redirect == IN_1 || redirect == IN_2)
		rfile->option = O_RDONLY;
	if (redirect == OUT_1)
		rfile->option = O_TRUNC | O_WRONLY | O_CREAT;
	if (redirect == OUT_2)
		rfile->option = O_WRONLY | O_CREAT | O_APPEND;
	rfile->args = NULL;
	rfile->next = NULL;
	return (rfile);
}

t_cmd	*_init_cmd(char *cmd)
{
	t_cmd	*r_cmd;
	int		i;

	r_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	r_cmd->nb_arg = ft_get_args_len(cmd);
	if (r_cmd->nb_arg == 0)
		r_cmd->args = NULL;
	else
	{
		r_cmd->args = (char **)malloc(sizeof(char *) * (r_cmd->nb_arg + 1));
		if (!r_cmd->args)
			return (NULL);
		i = r_cmd->nb_arg;
		while (i >= 0)
			r_cmd->args[i--] = NULL;
	}
	r_cmd->file_in = NULL;
	r_cmd->file_out = NULL;
	r_cmd->l_type = NONE;
	r_cmd->next = NULL;
	return (r_cmd);
}

void	*_next_cmd(void *value, t_list_type type)
{
	if (type == CMD)
		return (((t_cmd *)value)->next);
	if (type == R_FILE)
		return (((t_rfile *)value)->next);
	return (value);
}

void	_add_next_cmd(void *value, void *next, t_list_type type)
{
	if (type == CMD)
		((t_cmd *)value)->next = (t_cmd *)next;
	if (type == R_FILE)
		((t_rfile *)value)->next = (t_rfile *)next;
}
