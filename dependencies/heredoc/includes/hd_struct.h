/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:32:58 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/23 10:12:06 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HD_STRUCT_H
# define HD_STRUCT_H

typedef struct s_hd
{
	int			fd[2];
	size_t		size;
	int			pos;
	struct s_hd	*next;
}				t_hd;

#endif
