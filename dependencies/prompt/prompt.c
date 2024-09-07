/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 05:51:07 by ballain           #+#    #+#             */
/*   Updated: 2024/09/07 12:14:00 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

char	*get_prompt(char *msh_name, t_env *env)
{
	char	*prompt;

	prompt = NULL;
	while (prompt == NULL || is_only_spaces(prompt))
	{
		free(prompt);
		prompt = readline(msh_name);
	}
	if (check_syntax_err(prompt))
		return (NULL);
	while (is_uncomplete_prompt(prompt))
		prompt = ft_join_prompt(prompt, env);
	return (prompt);
}
