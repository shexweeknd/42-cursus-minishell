/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:16:48 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/15 20:26:29 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

void	echo(t_cmd *cmd)
{
	int	i;
	int	end;

	i = 1;
	end = '\n';
	if (ft_strcmp(cmd->args[i], "-n") == 0)
		i += ((end = 0), 1);
	while (cmd->args[i])
		printf("%s", cmd->args[i++]);
	printf("%c", end);
}
