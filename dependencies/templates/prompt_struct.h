/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:14:48 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/21 08:44:48 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_STRUCT_H
# define PROMPT_STRUCT_H

# include "cmd_struct.h"
# include "env_struct.h"
# include "hist_struct.h"

typedef struct s_prompt
{
	int			wait_nl;
	int			to_exit;
	int			to_execute;
	int			is_eof;
	char		*line;
	t_cmd		*cmd;
	t_env		*venv;
	t_hist_elem	*hist;
}				t_prompt;

#endif
