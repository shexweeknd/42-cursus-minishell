/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:58:57 by ballain           #+#    #+#             */
/*   Updated: 2024/09/19 10:50:44 by ballain          ###   ########.fr       */
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
# include <errno.h>

# define TILDE_PATH ""
# define STATUS	'0'

/* _________________________ SRC _________________________ */
int				cd(t_executable exec);
void			echo(t_executable exec);
void			ft_env(t_executable exec);
int				export(t_executable exec);
void			pwd(t_executable exec);
void			unset(t_executable exec);
void			ft_exit(t_executable exec);

int				ft_isvar(char *str);
int				ft_dqoute_len(char **arg, t_env *env, char *stop);
int				ft_dquote_add(char *dest, char **arg, t_env *env, char *stop);
void			*ft_manage_args(t_cmd *cmd, t_env *env);

/* _________________________ EXEC UTILS _________________________ */
void			ft_reset_fd(t_executable exec);
char			*ft_search_executable(t_executable exec);
t_executable	ft_init_executable(t_exec_params param);
void			ft_free_executable(t_executable exec);
char			*_join(char *str[]);

/* _________________________ EXEC _________________________ */
int				ft_exec_cmds(t_exec_params params);

#endif
