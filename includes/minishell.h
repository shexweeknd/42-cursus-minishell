/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:11:46 by ballain           #+#    #+#             */
/*   Updated: 2024/09/12 09:55:55 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "sig.h"
# include "cmd.h"
# include "env.h"
# include "ft_exec.h"
# include "history.h"
# include "m_err.h"
# include "prompt.h"
# include "struct.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define MSH_NAME "\033[0;32mMinishell$\033[0;0m "
# define HIST_PATH "./dependencies/history/src/minishell_history.txt"

#endif