/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:17:34 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/26 12:51:39 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

void	ft_exit(t_executable exec)
{
	(void)exec;
}

int	is_exit(char *line)
{
	int	index;
	int	result;

	if (!line)
		return (0);
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
			if (line[index] && !ft_isdigit(line[index]))
				printf("\033[0;32m%s:\033[0;0m exit: %c%s", "Minishell",
					line[index], ": numeric argument required\n");
			return (result);
		}
		index++;
	}
	return (result);
}

void	exit_msh(t_prompt *pt)
{
	char	*wd;

	wd = ft_strjoin(get_rootpath(), HIST_PATH);
	printf("exit\n");
	(set_history(pt->hist, wd), free(wd));
	free(pt->line);
	ft_free_env(pt->venv);
}
