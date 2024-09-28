/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:34:02 by ballain           #+#    #+#             */
/*   Updated: 2024/09/28 09:08:08 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_STRUCT_H
# define EXEC_STRUCT_H

# include "cmd_struct.h"
# include "env_struct.h"
# include "hist_struct.h"

typedef struct s_exec_params
{
	int			read_fd;
	t_cmd		*cmd;
	t_env		*env;
	t_hist_elem	*hist;
	t_link		l_type;
}				t_exec_params;

typedef struct s_executable
{
	int			o_fd[2];
	int			p_fd[2];
	int			s_fd[2];
	t_cmd		*cmd;
	t_env		*env;
	t_hist_elem	*hist;
}				t_executable;

#endif
