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

void	ft_exit(t_executable exec)
{
	(void)exec;
}

size_t	_skip_nbr(char *line)
{
	size_t	nbr_len;

	nbr_len = 0;
	while (ft_isspace(*line))
		nbr_len++;
	while (ft_isdigit(line[nbr_len]))
		nbr_len++;
	return (nbr_len);
}

int	is_valid_exit_args(char *line)
{
	int	index;

	index = 0;
	if (!line[index] || is_only_spaces(line))
		return (1);
	while (ft_isspace(line[index]))
		index++;
	if (!ft_isdigit(line[index]))
		return (printf("\033[0;32m%s:\033[0;0m exit: %c%s", MSH_LOG,
				line[index], ": numeric argument required\n"), set_status(2),
			0);
	if (ft_isdigit(line[index]) && ft_isnbr(&line[index]))
		set_status(ft_atoi(&line[index]));
	index += _skip_nbr(&line[index]);
	if (line[index])
		return (printf("\033[0;32m%s:\033[0;0m exit: %s", MSH_LOG,
				": too many arguments\n"), set_status(1), 0);
	return (1);
}

int	is_exit(char *line)
{
	int	index;

	if (!line)
		return (0);
	index = 0;
	while (line[index] && ft_isspace(line[index]))
		index++;
	if (!ft_strncmp(&line[index], "exit", 4))
		if (is_valid_exit_args(&line[index + 4]))
			return (1);
	return (0);
}

// TODO COMPLETE AND TEST
void	exit_msh(t_prompt *pt)
{
	char	*wd;

	wd = ft_strjoin(get_rootpath(), HIST_PATH);
	printf("exit\n");
	(set_history(pt->hist, wd), free(wd));
	free(pt->line);
	ft_free_env(pt->venv);
	ft_free_cmds(pt->cmd);
	exit(get_status());
}
