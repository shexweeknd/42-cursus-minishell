/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:36:33 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/21 09:38:07 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "../../env/includes/env.h"
# include "../../env/includes/env_struct.h"
# include "../../err/includes/m_err.h"
# include "../../heredoc/includes/hd.h"
# include "../../history/includes/history.h"
# include "../../sig/includes/sig.h"
# include "libft.h"
# include "prompt_struct.h"
# include <signal.h>

int		sig_type(char cmd, int value);
void	sec_prompt_sig_handler(int signal);
void	re_open_stdin(void);
void	to_stdin(char cmd);

int		is_pipe_at_end(char *line);
int		is_uncomplete_line(char *line);

char	*to_ps_two(char cmd, char *value);
char	*ft_join_line(t_prompt *prompt, char *line);
void	init_prompt(t_prompt *prompt, char **env, char *hist_path);
void	get_prompt(t_prompt *prompt, char *msh_name);

void	print_prompt(t_prompt *prompt);

#endif