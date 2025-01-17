/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:04:12 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/26 09:04:14 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIST_STRUCT_H
# define HIST_STRUCT_H

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

#endif
