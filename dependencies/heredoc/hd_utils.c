/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:53:46 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/23 13:52:44 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

int	_hd_occ(char *line)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	while (i < ft_strlen(line) && line[i])
	{
		if (line[i] == '<' && line[i + 1] == '<')
			result++;
		i++;
	}
	return (result);
}

void	recurse_free_hd(t_hd *hd)
{
	if (!hd)
	{
		free(hd);
		return ;
	}
	recurse_free_hd(hd->next);
	free(hd);
	return ;
}

void	recurse_close_hd(t_hd *hd)
{
	if (!hd)
		return ;
	close(hd->fd[0]);
	close(hd->fd[1]);
	recurse_close_hd(hd->next);
	return ;
}
