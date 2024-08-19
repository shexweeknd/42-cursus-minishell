/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:15:07 by ballain           #+#    #+#             */
/*   Updated: 2024/08/18 19:34:29 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static void	_free_cmd(void *value)
{
	int			i;

	if (!value)
		return ;
	i = 0;
	if (((t_cmd *)value)->args)
	{
		while (((t_cmd *)value)->args[i])
			free(((t_cmd *)value)->args[i++]);
		free(((t_cmd *)value)->args[i]);
		free(((t_cmd *)value)->args);
	}
	if (((t_cmd *)value)->file_in)
		free(((t_cmd *)value)->file_in);
	if (((t_cmd *)value)->file_out)
		free(((t_cmd *)value)->file_out);
	if (((t_cmd *)value)->file_append)
		free(((t_cmd *)value)->file_append);
	if (((t_cmd *)value)->heredoc)
		free(((t_cmd *)value)->heredoc);
	free(value);
}

void	ft_free_cmds(t_cmd *cmd)
{
	_loop((void **)&cmd, (t_lst_utils){CMD, _free_cmd, _next_cmd});
}
