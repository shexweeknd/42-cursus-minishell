/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:17:34 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/26 17:09:21 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

// TODO ameliorer
int valid_exit_args(t_cmd *cmd)
{
	if (cmd->l_type == PIPE)
		printf("ltype: pipe\n");
	if (!cmd->args[1])
	{
		if (!cmd->next)
			printf("exit\n");
		return (1);
	}
	// valide si arg n'est pas digit donc set status a get_status puis retourne get_status
	if (!ft_isnbr(cmd->args[1]))
	{
		if (!cmd->next)
			printf("exit\n");
		return (printf("\033[0;32m%s:\033[0;0m exit: %s%s", MSH_LOG, cmd->args[1], ": numeric argument required\n"),
				set_status(2), 1);
	}
	// non valide si too many args
	else if (cmd->args[2])
		return (printf("\033[0;32m%s:\033[0;0m exit: %s", MSH_LOG,
					   ": too many arguments\n"),
				set_status(ft_atoi(cmd->args[1])), 0);
	return (0);
}

void ft_exit(t_executable exec)
{
	char *wd;

	wd = ft_strjoin(get_rootpath(), HIST_PATH);
	if (valid_exit_args(exec.cmd))
	{
		(set_history(exec.hist, wd), free(wd));
		ft_free_env(exec.env);
		ft_free_cmds(exec.cmd);
		exit(get_status());
	}
}
