/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:36:33 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/27 11:43:07 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "libft.h"
# include "sig.h"
# include "prompt_struct.h"
# include "m_err.h"
# include "env.h"
# include "hd.h"
# include "history.h"
# include "ft_static.h"
# include <signal.h>

void	re_open_stdin(void);

int		is_pipe_at_end(char *line);
int		is_uncomplete_line(char *line);

char	*to_ps_two(char cmd, char *value);
char	*ft_join_line(t_prompt *prompt, char *line);
void	init_prompt(t_prompt *prompt, char **env, char *hist_path);
void	get_prompt(t_prompt *prompt, char *msh_name);
void	setup_prompt_flags(t_prompt *prompt);

void	print_prompt(t_prompt *prompt);

#endif