/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:36:33 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/11 14:38:24 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "../../env/includes/env.h"
# include "../../env/includes/env_struct.h"
# include "../../err/includes/m_err.h"
# include "libft.h"
# include "prompt_struct.h"
# include <signal.h>

void	re_open_stdin(void);

int		is_pipe_at_end(char *line);
int		is_uncomplete_line(char *line);

char	*get_col_ps_two(t_env *env);
char	*ft_join_line(t_prompt *prompt, char *line);
void	init_prompt(t_prompt *prompt);
void	get_prompt(t_prompt *prompt, char *msh_name);

void	print_prompt(t_prompt *prompt);

#endif