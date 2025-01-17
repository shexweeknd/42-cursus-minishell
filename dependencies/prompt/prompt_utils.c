/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:33:07 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/07 13:05:52 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

void	init_prompt(t_prompt *prompt, char **envp, char *hist_path)
{
	prompt->wait_nl = 0;
	prompt->to_exit = 0;
	prompt->to_execute = 1;
	prompt->is_eof = 0;
	prompt->line = NULL;
	prompt->cmd = NULL;
	prompt->venv = ft_getenv(envp);
	prompt->hist = get_history(hist_path);
	setsenv(prompt->venv);
}

void	setup_prompt_flags(t_prompt *prompt)
{
	if (sig_type('g', 0) == SIGINT)
	{
		prompt->wait_nl = 0;
		prompt->to_exit = 0;
		prompt->to_execute = 0;
		prompt->is_eof = 0;
		to_stdin('o');
	}
	else
	{
		prompt->wait_nl = 0;
		prompt->to_exit = 1;
		prompt->to_execute = 0;
		prompt->is_eof = 1;
	}
	sig_type('r', 0);
}

char	*get_colored_ps_two(void)
{
	char	*result;
	char	*tmp;
	char	*ps_two;

	ps_two = to_ps_two('g', NULL);
	tmp = ft_strjoin("\033[0;32m", ps_two);
	result = ft_strjoin(tmp, "\033[0;0m");
	return (free(tmp), result);
}

char	*ft_join_line(t_prompt *prompt, char *line)
{
	char	*result;
	char	*tmp;
	char	*new_line;

	if (prompt->wait_nl == 0)
		return (line);
	result = NULL;
	new_line = NULL;
	(set_status(0), signal(SIGINT, sec_sig_handler));
	while (prompt->wait_nl && (!new_line || is_only_spaces(new_line)))
	{
		free(new_line);
		new_line = readline(to_ps_two('g', NULL));
		if (!new_line)
			break ;
	}
	if (_hd_occ(new_line) && hd_check_syntax_err(new_line))
		return (free(new_line), line);
	if (new_line == NULL)
		return (setup_prompt_flags(prompt), free(new_line),
			line);
	tmp = ft_strjoin(" ", new_line);
	result = ft_strjoin(line, tmp);
	return (free(line), free(tmp), free(new_line), result);
}
