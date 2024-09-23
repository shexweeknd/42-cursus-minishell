/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:17:34 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/23 13:43:12 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

void	ft_exit(t_executable exec)
{
	(void)exec;
	// return (printf("exit\n"), set_history(pt.hist, HIST_PATH),
	// 			free(pt.line), ft_free_env(pt.venv), 0);
}

int		is_exit(char *line)
{
	int	index;
	int	result;

	result = 0;
	index = 0;
	while (line[index])
	{
		if (!ft_strncmp(&line[index], "exit", 4))
		{
			index += 4;
			if (!line[index] || ft_isspace(line[index]))
				result = 1;
			while (line[index] && ft_isspace(line[index]))
				index++;
			if (!line[index])
				return (result);
			else if (!ft_isdigit(line[index]))
				return (printf("\033[0;32m%s: \033[0;0m exit: %c: numeric argument required\n", "Minishell",
			line[index]), result);
		}
		index++;
	}
	return (result);
}

void	exit_msh(t_prompt *pt)
{
	printf("exit\n");
	set_history(pt->hist, HIST_PATH);
	free(pt->line);
	ft_free_env(pt->venv);
}
