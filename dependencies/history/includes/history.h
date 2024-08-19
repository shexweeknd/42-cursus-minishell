/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:38:41 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/19 14:19:23 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>

enum					e_hist_err_status
{
	ERROR_READ_STATUS,
	ERROR_WRITE_STATUS,
	SUCCESS_READ_STATUS,
	SUCCESS_WRITE_STATUS
};

typedef struct s_hist_elem
{
	int					is_offset;
	int					line_nbr;
	char				*command;
	struct s_hist_elem	*next;
}						t_hist_elem;

// principal functions
t_hist_elem				*get_history(char *file_path);
int						set_history(t_hist_elem *hist_elem, char *file_path);

// functions for get_history
size_t					count_files_line(char *history_path);
t_hist_elem				*ft_append_hist_elem(t_hist_elem *first_elem,
							char *command);
t_hist_elem				*ft_get_last_history(t_hist_elem *elem);
t_hist_elem				*ft_get_history_offsetted(t_hist_elem *elem);

// functions for set_history
void					go_to_offset(int fd, t_hist_elem *hist_elem);
char					*get_things_after_offset(int fd);
void					write_cmd_typed_after_offset(int fd, t_hist_elem *hist);

// utils function for everyone
void					*get_next_history(t_hist_elem *src);
void					add_back_history(t_hist_elem *src, t_hist_elem *new);
void					free_lchistory(t_hist_elem *hist_elem);

// debugging functions
void					display_rlhistory(void);
void					display_lchistory(t_hist_elem *hist_elem);
void					show_formatted_rlhistory(void);

#endif