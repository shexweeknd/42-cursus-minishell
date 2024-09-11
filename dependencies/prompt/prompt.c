/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 05:51:07 by ballain           #+#    #+#             */
/*   Updated: 2024/09/11 13:58:25 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

char	*get_line(t_prompt *prompt, char *msh_name)
{
	char	*line;

	line = NULL;
	while (line == NULL || is_only_spaces(line))
	{
		free(line);
		line = readline(msh_name);
	}
	if (check_syntax_err(line))
		return (NULL);
	if (is_uncomplete_line(line))
		prompt->wait_nl = 1;
	while (prompt->wait_nl && is_uncomplete_line(line))
	{
		line = ft_join_line(prompt, line);
		if (check_syntax_err(ft_strdup(line)))
			return (line);
	}
	return (line);
}

void	get_prompt(t_prompt *prompt, char *msh_name)
{
	prompt->wait_nl = 0;
	prompt->to_exit = 0;
	prompt->to_execute = 1;
	prompt->is_eof = 0;
	prompt->line = get_line(prompt, msh_name);
	if (is_uncomplete_line(prompt->line) && prompt->is_eof)
		printf("\033[0;32m%s:\033[0;0m%s\n", "Minishell",
			": syntax error: unexpected end of file");
}
