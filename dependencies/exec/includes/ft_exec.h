/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:58:57 by ballain           #+#    #+#             */
/*   Updated: 2024/09/26 11:44:55 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H

# include "cmd.h"
# include "env.h"
# include "exec_struct.h"
# include "ft_status.h"
# include "history.h"
# include "libft.h"
# include "prompt_struct.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/* _________________________ SRC _________________________ */
int				pwd(t_executable exec);
int				cd(t_executable exec);
int				echo(t_executable exec);
int				ft_env(t_executable exec);
int				export(t_executable exec);
int				unset(t_executable exec);
void			ft_exit(t_executable exec);
void			exit_msh(t_prompt *pt);

/* _________________________ MANAGE ARGS _________________________ */
int				is_exit(char *line);
int				ft_isvar(char *str);
int				ft_lenvar(char *arg, t_env *env, int lenv);
int				ft_cpvar(char *dest, char *arg, t_env *env, int lenv);
int				ft_getlen_status(void);
int				ft_add_status(char *dest);
int				ft_dqoute_len(char **arg, t_env *env, char *stop);
int				ft_dquote_add(char *dest, char **arg, t_env *env, char *stop);
void			*ft_manage_args(t_cmd *cmd, t_env *env);

/* _________________________ EXEC UTILS _________________________ */
char			*ft_search_executable(t_executable exec);
t_executable	ft_init_executable(t_exec_params param);
void			ft_free_executable(t_executable exec, t_cmd *cmd);
void			ft_next_cmds(int fd[2], t_exec_params params);
int				ft_check_valid_var(char *var, int status);

/* _________________________ EXEC STATUS _________________________ */
void			p_exec_log(char *msg, char *file_exe);
int				cmd_found(char *file_exe, int simulate);
int				cmd_executable(char *file_exe, int simulate);
char			*is_exec_from_path(t_executable *exec);

/* _________________________ EXEC _________________________ */
int				ft_exec_cmds(t_exec_params params);

/* _________________________ PATH _________________________ */
char			*get_rootpath(void);
void			set_rootpath(char *new_root_path);

/* _________________________ FD _________________________ */
void			ft_reset_fd(t_executable exec);
void			ft_manage_redirect_file(int fd[2], t_cmd *cmd);
int				ft_pipe_status(int fd[0], int value, int send);

#endif
