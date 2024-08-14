/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:38:41 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/14 15:54:09 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "libft.h"
# include <stdio.h>

typedef struct s_hist_elem
{
	int					is_offset_to_write;
	int					line_number;
	char				*command;
	struct s_hist_elem	*next;
}						t_hist_elem;

// principal functions
void					set_history(t_hist_elem *hist_elem, char *history_path);
t_hist_elem				*get_history(char *history_path);

// functions for get_history
size_t					count_files_line(char *history_path);
t_hist_elem				*ft_append_hist_elem(t_hist_elem *first_elem,
							char *command, int position);
t_hist_elem				*ft_get_last_history(t_hist_elem *elem);
t_hist_elem				*ft_get_history_offsetted(t_hist_elem *elem);

// functions for set_history
void					go_to_offset(int fd, t_hist_elem *hist_elem);
char					*get_things_after_offset(int fd);

// utils function for everyone
void					free_history(t_hist_elem *hist_elem);

// debugging functions
void					print_history(t_hist_elem *hist_elem);

#endif