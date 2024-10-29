/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:40:56 by ballain           #+#    #+#             */
/*   Updated: 2024/10/29 13:52:37 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_file_exist(char *file_name)
{
	if (access(file_name, F_OK) == -1)
	{
		ft_perror_fd(2, (char *[]){MSH_LOG, ": ", \
		file_name, ": No such file or directory", NULL});
		return (0);
	}
	return (1);
}

int	ft_open(char *file_name, int option)
{
	int	fd;

	fd = open(file_name, option, 0644);
	if (fd == -1)
	{
		ft_perror_fd(2, (char *[]){MSH_LOG, ": ", \
		file_name, ": No such file or directory", NULL});
		return (-1);
	}
	if (!ft_file_exist(file_name))
		return (-1);
	return (fd);
}
