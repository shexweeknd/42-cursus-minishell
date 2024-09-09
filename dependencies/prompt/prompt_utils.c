/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:33:07 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/09 09:05:21 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

// TODO replace '>' with content of variable $PS2
// col_ps_two = get_col_ps_two(env);
char	*ft_join_prompt(char *prompt, t_env *env)
{
	char	*result;
	char	*tmp;
	char	*new_prompt;
	char	*col_ps_two;

	(void)env;
	new_prompt = NULL;
	result = NULL;
	col_ps_two = ft_strdup("\033[0;32m>\033[0;0m ");
	while (new_prompt == NULL || is_only_spaces(new_prompt))
	{
		free(new_prompt);
		new_prompt = readline(col_ps_two);
	}
	tmp = ft_strjoin(" ", new_prompt);
	result = ft_strjoin(prompt, tmp);
	return (free(col_ps_two), free(prompt), free(tmp), free(new_prompt),
		result);
}

int	is_pipe_at_end(char *prompt)
{
	int	cursor;

	cursor = 0;
	while (prompt[cursor])
		cursor++;
	while (cursor && prompt[cursor--] == ' ')
		;
	if (prompt[cursor] == '|')
		return (1);
	return (0);
}

int	is_and_at_end(char *prompt)
{
	int	cursor;

	cursor = 0;
	while (prompt[cursor])
		cursor++;
	while (cursor && prompt[cursor--] == ' ')
		;
	if (prompt[cursor] == '&' && cursor >= 2)
	{
		if (prompt[cursor - 1] == '&')
			return (1);
	}
	return (0);
}

// TODO FORENSICS OF PROMPT THAT DISPLAYS PS2
int	is_uncomplete_prompt(char *prompt)
{
	if (is_pipe_at_end(prompt))
		return (1);
	if (is_and_at_end(prompt))
		return (1);
	return (0);
}
