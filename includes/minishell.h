/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:11:46 by ballain           #+#    #+#             */
/*   Updated: 2024/09/25 19:39:33 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "env.h"
# include "ft_status.h"
# include "hd.h"
# include "m_err.h"
# include "sig.h"
# include "history.h"
# include "prompt.h"
# include "cmd.h"
# include "ft_exec.h"
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

#endif