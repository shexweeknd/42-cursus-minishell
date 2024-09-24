/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:54:12 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/24 12:56:07 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void	*get_next_history(t_hist_elem *src)
{
	return (src->next);
}

void	add_back_history(t_hist_elem *src, t_hist_elem *new)
{
	src->next = new;
}

void	free_lchistory(t_hist_elem *hist_elem)
{
	if (!hist_elem)
		return ;
	if (!hist_elem->next)
	{
		free(hist_elem->command);
		free(hist_elem);
		return ;
	}
	rl_clear_history();
	free_lchistory(hist_elem->next);
	free(hist_elem->command);
	free(hist_elem);
	return ;
}

char	*hist_path(char *new_path, int save)
{
	static char	*path = "/dependencies/history/src/minishell_history.txt";

	if (save)
		path = new_path;
	return (path);
}
