/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:16:48 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/17 10:03:38 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

void	echo(t_executable exec)
{
	int	i;
	int	end;

	i = 1;
	end = '\n';
	if (exec.cmd->args[i] && ft_strcmp(exec.cmd->args[i], "-n") == 0)
		i += ((end = 0), 1);
	while (exec.cmd->args[i])
	{
		if (exec.cmd->args[i + 1])
			printf("%s ", exec.cmd->args[i++]);
		else
			printf("%s", exec.cmd->args[i++]);
	}
	printf("%c", end);
}
