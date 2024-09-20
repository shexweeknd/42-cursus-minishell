/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:53:01 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/20 10:36:14 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "heredoc_struct.h"
# include "libft.h"

void	process_hd(char *line);
int		_hd_occ(char *line);

#endif