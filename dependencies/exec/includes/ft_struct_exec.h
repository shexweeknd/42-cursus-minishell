/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_exec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:34:02 by ballain           #+#    #+#             */
/*   Updated: 2024/09/11 16:10:28 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_EXEC_H
# define FT_STRUCT_EXEC_H

# include "cmd.h"
# include "env.h"

typedef struct s_exec_prams
{
	int			read_fd;
	t_cmd		*src;
	t_cmd		*cmd;
	t_env		*env;
	t_link		l_type;
}	t_exec_params;

#endif
