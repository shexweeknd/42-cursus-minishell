/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:11:59 by ballain           #+#    #+#             */
/*   Updated: 2024/09/27 17:12:59 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_perror_fd(int fd, char *var[])
{
	int	i;

	i = -1;
	while (var[++i])
		write(fd, var[i], ft_strlen(var[i]));
	write(fd, "\n", 1);
}
