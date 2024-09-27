/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:11:46 by ballain           #+#    #+#             */
/*   Updated: 2024/09/27 11:48:15 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "cmd.h"
# include "env.h"
# include "ft_exec.h"
# include "ft_static.h"
# include "hd.h"
# include "history.h"
# include "libft.h"
# include "m_err.h"
# include "msh_mac.h"
# include "prompt.h"
# include "sig.h"
# include "struct.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

#endif