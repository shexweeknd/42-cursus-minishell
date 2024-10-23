/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:31:35 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/23 08:13:07 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

int	eof_size(char *line)
{
	int		i;
	char	*end;
	char	quote;

	i = 0;
	quote = 0;
	while (*line && !ft_is_cmd_sep(*line))
	{
		if ((!ft_strncmp(line, "$\"", 2) || !ft_strncmp(line, "$'", 2)) \
		&& *(line - 1) && *(line - 1) != '$')
			quote = *(++line);
		if (!quote)
			end = ((quote = ft_is_quote(*line)), NULL);
		if (quote)
		{
			end = ft_strchr((line + 1), quote);
			if (end)
				line = ((i += end - (line + 1)), ++end);
		}
		if (!end)
			i += ((line += 1), 1);
		if (quote)
			quote = 0;
	}
	return (i);
}

static int	_get_eof(char *eof, char *line)
{
	int	have_quote;

	have_quote = 0;
	while (line && *line && !ft_is_cmd_sep(*line) && !ft_is_redirect(*line))
	{
		if ((ft_is_quote(*line) && line++) \
			|| ((!ft_strncmp(line, "$\"", 2) || !ft_strncmp(line, "$'", 2)) \
			&& *(line - 1) \
			&& *(line - 1) != '$' && ((line++), line++)))
		{
			while (line && *line && !ft_is_quote(*line))
				*(eof++) = *(line++);
			if (line && *line && ft_is_quote(*line))
				line++;
			have_quote = 1;
		}
		else
			*(eof++) = *(line++);
	}
	return (have_quote);
}

static int	get_eof(char **dest, char *line)
{
	*dest = NULL;
	while (line && *line && *(line + 1) && !ft_strncmp(line, "<<", 2))
		line += 2;
	while (line && *line && ft_isspace(*line))
		line++;
	if (line && *line)
	{
		*dest = ft_calloc(eof_size(line) + 1, sizeof(char));
		if (!*dest)
			return (0);
		return (!_get_eof(*dest, line));
	}
	return (0);
}

t_eofs	*append_eofs(t_eofs *eofs, char *prompt)
{
	t_eofs	*eofs_start;
	int		expanded;
	char	*eof;

	expanded = get_eof(&eof, prompt);
	if (!eof)
		return (eofs);
	if (!eofs)
	{
		eofs = malloc(sizeof(t_eofs));
		if (!eofs)
			return (NULL);
		eofs->have_expanded = expanded;
		eofs->next = ((eofs->eof = eof), NULL);
		return (eofs);
	}
	eofs_start = eofs;
	while (eofs->next)
		eofs = eofs->next;
	eofs = ((eofs->next = malloc(sizeof(t_eofs))), eofs->next);
	if (!eofs)
		return (NULL);
	eofs->have_expanded = expanded;
	eofs->next = ((eofs->eof = eof), NULL);
	return (eofs_start);
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
