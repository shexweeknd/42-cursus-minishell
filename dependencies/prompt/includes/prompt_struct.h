/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:14:48 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/11 14:28:49 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_STRUCT_H
# define PROMPT_STRUCT_H

typedef struct s_prompt
{
	char	*ps_two;
	int		wait_nl;
	int		to_exit;
	int		to_execute;
	int		is_eof;
	char	*line;
}			t_prompt;

#endif
