/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:38:41 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/13 15:06:28 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "libft.h"
# include <stdio.h>

typedef struct s_hist_elem
{
	int					is_offset_to_write;
	char				*command;
	struct s_hist_elem	*next;
}						t_hist_elem;

// principal functions
void					set_history(char *history_path);
t_hist_elem				*get_history(char *history_path);

// functions for get_history
size_t					count_files_line(char *history_path);
t_hist_elem				*ft_append_hist_elem(t_hist_elem *first_elem,
							char *command);

// utils function for everyone
void					free_history(t_hist_elem *hist_elem);

// debugging functions
void					print_history(t_hist_elem *hist_elem);

#endif