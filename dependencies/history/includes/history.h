/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:38:41 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/13 12:55:25 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "libft.h"
# include <stdio.h>

typedef struct s_hist_elem
{
	int					pos;
	char				*command;
	struct s_hist_elem	*next;
}						t_hist_elem;

// principal functions
void					set_history(char *history_path);
t_hist_elem				*get_history(char *history_path);

// functions for get_history
size_t					count_files_line(char *file_path);
char					**parse_twodim(char *history_path);

// utils function for everyone
void					free_history(t_hist_elem *hist_elem);

#endif