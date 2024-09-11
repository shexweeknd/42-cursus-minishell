/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:33:07 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/11 14:32:46 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	init_prompt(t_prompt *prompt)
{
	prompt->to_exit = 0;
	prompt->to_execute = 1;
	prompt->wait_nl = 0;
	prompt->ps_two = "> ";
	prompt->line = NULL;
}

int		g_sig_type;

void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		close(STDIN_FILENO);
		printf("\n");
	}
	g_sig_type = signal;
}

void	setup_prompt_flags(t_prompt *prompt)
{
	if (g_sig_type == SIGINT)
	{
		prompt->wait_nl = 0;
		prompt->to_exit = 0;
		prompt->to_execute = 0;
		prompt->is_eof = 0;
		re_open_stdin();
	}
	else
	{
		prompt->wait_nl = 0;
		prompt->to_exit = 1;
		prompt->to_execute = 0;
		prompt->is_eof = 1;
	}
	g_sig_type = 0;
}

// TODO replace '>' with content of variable $PS2
// col_ps_two = get_col_ps_two(env);
char	*ft_join_line(t_prompt *prompt, char *line)
{
	char	*result;
	char	*tmp;
	char	*new_line;
	char	*col_ps_two;

	if (prompt->wait_nl == 0)
		return (line);
	result = NULL;
	new_line = NULL;
	col_ps_two = "\033[0;32m>\033[0;0m ";
	(signal(SIGQUIT, sig_handler), signal(SIGINT, sig_handler));
	while (prompt->wait_nl && is_only_spaces(new_line))
	{
		free(new_line);
		new_line = readline(col_ps_two);
		if (!new_line)
			break ;
	}
	if (new_line == NULL)
		return (setup_prompt_flags(prompt), free(new_line), line);
	tmp = ft_strjoin(" ", new_line);
	result = ft_strjoin(line, tmp);
	return (free(line), free(tmp), free(new_line), result);
}
