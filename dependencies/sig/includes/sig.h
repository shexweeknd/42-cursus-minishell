/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:37:40 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/12 12:07:28 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

# include <readline/readline.h>
# include <signal.h>
# include <unistd.h>

void	setup_main_signals(void);
void	setup_child_signals(void);

#endif