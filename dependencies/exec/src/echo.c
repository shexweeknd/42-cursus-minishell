/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:16:48 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/16 13:58:48 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	chech_option(char *arg)
{
	if (ft_strncmp(arg, "-n", 2) == 0)
	{
		arg += 2;
		while (arg && *arg)
		{
			if (*arg != 'n')
				return (0);
			arg++;
		}
		return (1);
	}
	return (0);
}

int	echo(t_executable exec)
{
	int	i;
	int	end;

	i = 1;
	end = '\n';
	while (exec.cmd->args[i] && chech_option(exec.cmd->args[i]))
		i += ((end = 0), 1);
	while (exec.cmd->args[i])
	{
		if (exec.cmd->args[i + 1])
			printf("%s ", exec.cmd->args[i++]);
		else
			printf("%s", exec.cmd->args[i++]);
	}
	printf("%c", end);
	return (0);
}
