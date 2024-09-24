/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:31:35 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/24 14:37:19 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

int	eof_size(char *line)
{
	int	result;

	result = 0;
	while (line[result] && !ft_isspace(line[result]))
		result++;
	return (result);
}

char	*get_eof(char *line)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (line[i] && line[i + 1])
	{
		if (!ft_strncmp(&line[i], "<<", 2))
		{
			i += 2;
			while (ft_isspace(line[i]))
				i++;
			result = malloc(sizeof(char) * (eof_size(&line[i]) + 1));
			if (!result)
				return (NULL);
			j = 0;
			while (line[i] && !ft_isspace(line[i]) && !ft_is_delimiter(line[i])
				&& !ft_is_redirect(line[i]))
				result[j++] = line[i++];
			result[j] = '\0';
			return (result);
		}
		i++;
	}
	return (NULL);
}

void	free_eofs(t_eofs *eofs)
{
	if (!eofs)
		return ;
	free(eofs->eof);
	free_eofs(eofs->next);
	free(eofs);
	return ;
}

t_eofs	*append_eofs(t_eofs *eofs, char *eof)
{
	t_eofs	*eofs_start;

	if (!eof)
		return (eofs);
	if (!eofs)
	{
		eofs = malloc(sizeof(t_eofs));
		if (!eofs)
			return (NULL);
		eofs->eof = eof;
		eofs->next = NULL;
		return (eofs);
	}
	eofs_start = eofs;
	while (eofs->next)
		eofs = eofs->next;
	eofs->next = malloc(sizeof(t_eofs));
	eofs = eofs->next;
	if (!eofs)
		return (NULL);
	eofs->eof = eof;
	eofs->next = NULL;
	return (eofs_start);
}
