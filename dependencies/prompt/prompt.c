/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 05:51:07 by ballain           #+#    #+#             */
/*   Updated: 2024/09/23 13:15:11 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

// TODO process heredoc if valid format before syntax error
char	*get_line(t_prompt *prompt, char *msh_name)
{
	char	*line;

	line = NULL;
	while (line == NULL || is_only_spaces(line))
	{
		free(line);
		line = readline(msh_name);
		if (line == NULL)
			return (prompt->to_exit = 1, free(line), NULL);
	}
	if (check_syntax_err(line))
		return (line);
	if (is_uncomplete_line(line))
		prompt->wait_nl = 1;
	while (prompt->wait_nl && is_uncomplete_line(line))
	{
		line = ft_join_line(prompt, line);
		if (check_syntax_err(line))
			break ;
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
			" syntax error: unexpected end of file");
}
