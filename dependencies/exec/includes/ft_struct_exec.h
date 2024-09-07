/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_exec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:34:02 by ballain           #+#    #+#             */
/*   Updated: 2024/09/07 08:37:26 by ballain          ###   ########.fr       */
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
	t_link		link_type;
}	t_exec_params;

#endif
