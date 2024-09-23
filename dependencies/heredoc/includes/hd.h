/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:53:01 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/23 12:26:21 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HD_H
# define HD_H

# include "../../prompt/includes/prompt.h"
# include "hd_struct.h"
# include "libft.h"

t_hd	*hd_cmd(char cmd, char *eof);
void	process_hd(char *line);
int		_hd_occ(char *line);
char	*get_eof(char *line);
size_t	fullfill_fd(int fd, char *eof);
char	*get_hd(int fd, size_t size);
void	recurse_free_hd(t_hd *hd);
void	recurse_close_hd(t_hd *hd);

void	print_hd(t_hd *hd);

#endif