/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:14:48 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/12 09:44:22 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_STRUCT_H
# define PROMPT_STRUCT_H

typedef struct s_prompt
{
	char		*ps_two;
	int			wait_nl;
	int			to_exit;
	int			to_execute;
	int			is_eof;
	int			is_child;
	char		*line;
	t_cmd		*cmd;
	t_env		*venv;
	t_hist_elem	*hist;
}				t_prompt;

#endif
