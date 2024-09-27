/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 05:51:07 by ballain           #+#    #+#             */
/*   Updated: 2024/09/27 08:40:45 by hramaros         ###   ########.fr       */
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
		if (line == NULL)
			return (prompt->to_exit = 1, NULL);
	}
	if (check_syntax_err(line, 1))
		return (prompt->to_execute = 0, line);
	if (!get_status() && is_uncomplete_line(line))
		prompt->wait_nl = 1;
	while (prompt->wait_nl && is_uncomplete_line(line))
	{
		line = ft_join_line(prompt, line);
		if (check_syntax_err(line, 0))
			return (prompt->to_execute = 0, line);
	}
	return (line);
}

void	get_prompt(t_prompt *prompt, char *msh_name)
{
	sig_type('s', 0);
	prompt->wait_nl = 0;
	prompt->to_exit = 0;
	prompt->to_execute = 1;
	prompt->is_eof = 0;
	prompt->line = get_line(prompt, msh_name);
	if (is_uncomplete_line(prompt->line) && prompt->is_eof)
		ft_printf_fd("\033[0;32m%s:\033[0;0m%s\n", 2, MSH_LOG,
			" syntax error: unexpected end of file");
	if ((get_status() == 2) && _hd_occ(prompt->line))
		hd_cmd('f', NULL);
	if (sig_type('g', 0) == SIGINT)
		prompt->to_execute = 0;
}
