/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:37:40 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/12 11:54:00 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

# include <readline/readline.h>
# include <signal.h>
# include <unistd.h>

void	do_noth(int sig);
void	setup_main_signals(void);
void	unsetup_main_signals(void);

#endif