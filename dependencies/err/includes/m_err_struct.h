/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_err_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:03:55 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/30 10:13:38 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_ERR_STRUCT_H
# define M_ERR_STRUCT_H

# include "libft.h"

enum
{
	UNEXPECTED_TOKEN,
};

typedef struct s_err
{
	int		err_type;
	char	*message;
}			t_err;

#endif
