/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:53:46 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/24 14:43:41 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

int	skip_until_hd(char *line)
{
	int	result;

	result = 0;
	while (line[result] && ft_strncmp(&line[result], "<<", 2))
		result++;
	return (result);
}

int	skip_hd_eof(char *line)
{
	int	result;

	result = 0;
	if (!ft_strncmp(line, "<<", 2))
		result += 2;
	while (ft_isspace(line[result]))
		result++;
	while (!ft_isspace(line[result]))
	{
		if (!line[result] || ft_is_delimiter(line[result])
			|| ft_is_redirect(line[result]))
			break ;
		result++;
	}
	return (result);
}

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
