/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:53:01 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/23 16:19:07 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HD_H
# define HD_H

# include "../../prompt/includes/prompt.h"
# include "hd_struct.h"
# include "libft.h"

t_hd	*hd_cmd(char cmd, char *eof);
void	process_hd(t_eofs *eofs);
int		_hd_occ(char *line);
size_t	fullfill_fd(int fd, char *eof);
char	*get_hd(int fd, size_t size);
void	recurse_free_hd(t_hd *hd);
void	recurse_close_hd(t_hd *hd);

char	*get_eof(char *line);
t_eofs	*append_eofs(t_eofs *eofs, char *eof);
void	free_eofs(t_eofs *eofs);

void	print_hd(t_hd *hd);

#endif