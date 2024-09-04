/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_exec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:31:04 by ballain           #+#    #+#             */
/*   Updated: 2024/09/04 08:31:05 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_EXEC_H
# define FT_STRUCT_EXEC_H

# include "cmd.h"
# include "env.h"

typedef struct s_exec_params
{
	int			read_fd;
	t_cmd		*cmd;
	t_env_var	*venv;
	t_link		link_type;
}	t_exec_params;

#endif
