/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:37:40 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/25 20:40:02 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

# include "ft_status.h"
# include <readline/readline.h>
# include <signal.h>
# include <unistd.h>

void	setup_main_signals(void);
void	setup_child_signals(void);
int		sec_prompt_flag(char cmd, int value);
void	to_stdin(char cmd);
void	sec_sig_handler(int signal);
int		sig_type(char cmd, int value);

#endif