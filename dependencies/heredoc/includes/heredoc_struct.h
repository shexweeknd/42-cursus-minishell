/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:32:58 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/20 10:46:48 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_STRUCT_H
# define HEREDOC_STRUCT_H

typedef struct s_hd
{
	int			fd[2];
	int			pos;
	struct s_hd	*next;
}				t_hd;

#endif
