/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:38:41 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/26 08:46:33 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "hist_struct.h"
# include "libft.h"
# include "msh_mac.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>

// principal functions
t_hist_elem	*get_history(char *file_path);
int			set_history(t_hist_elem *hist_elem, char *file_path);

// functions for get_history
size_t		count_files_line(char *history_path);
t_hist_elem	*ft_append_hist_elem(t_hist_elem *first_elem, char *command);
t_hist_elem	*ft_get_last_history(t_hist_elem *elem);
t_hist_elem	*ft_get_history_offsetted(t_hist_elem *elem);

// functions for set_history
void		go_to_offset(int fd, t_hist_elem *hist_elem);
char		*get_things_after_offset(int fd);
void		write_cmd_typed_after_offset(int fd, t_hist_elem *hist);

// utils functions for everyone
void		*get_next_history(t_hist_elem *src);
void		add_back_history(t_hist_elem *src, t_hist_elem *new);
void		free_lchistory(t_hist_elem *hist_elem);

// debugging functions
void		show_formatted_lchist(t_hist_elem *lchist);
void		display_lchist(t_hist_elem *hist_elem);

#endif