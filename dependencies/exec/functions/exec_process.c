/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:22:02 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/24 13:22:15 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	cmd_found(char *file_exe, int simulate)
{
	if (simulate)
	{
		ft_perror_fd(2, (char *[]){MSH_LOG, ": ", file_exe, ": ",
			"command not found", NULL});
		return (set_status(127), 0);
	}
	if (access(file_exe, F_OK) == 0)
		return (1);
	ft_perror_fd(2, (char *[]){MSH_LOG, ": ", file_exe, ": ",
		"No such file or directory", NULL});
	return (set_status(127), 0);
}

int	cmd_executable(char *file_exe, int simulate)
{
	if (simulate)
	{
		ft_perror_fd(2, (char *[]){MSH_LOG, ": ", file_exe, ": ",
			"Permission denied", NULL});
		return (set_status(126), 0);
	}
	if (access(file_exe, X_OK) == 0)
		return (1);
	ft_perror_fd(2, (char *[]){MSH_LOG, ": ", file_exe, ": ",
		"Permission denied", NULL});
	return (set_status(126), 0);
}
