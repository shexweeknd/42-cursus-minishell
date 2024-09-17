/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:58:57 by ballain           #+#    #+#             */
/*   Updated: 2024/09/16 19:52:34 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H

# include "cmd.h"
# include "env.h"
# include "ft_struct_exec.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define STATUS	'0'

/* _________________________ SRC _________________________ */
void	cd(t_cmd *cmd);
void	echo(t_cmd *cmd);
void	ft_env(t_env *env);
void	export(t_cmd *cmd);
void	pwd(t_cmd *cmd);
void	unset(t_cmd *cmd);
void	ft_exit(void);

int		ft_isvar(char *str);
int		ft_dqoute_len(char **arg, t_env *env, char *stop);
int		ft_dquote_add(char *dest, char **arg, t_env *env, char *stop);
void	*ft_manage_args(t_cmd *cmd, t_env *env);

/* _________________________ EXEC UTILS _________________________ */
void	ft_reset_fd(t_executable exec);
char	*ft_search_executable(t_executable exec);
t_executable	ft_init_executable(t_exec_params param);

/* _________________________ EXEC _________________________ */
int		ft_exec_cmds(t_exec_params params);

#endif
