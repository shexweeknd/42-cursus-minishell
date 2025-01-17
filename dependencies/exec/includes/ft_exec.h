/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:58:57 by ballain           #+#    #+#             */
/*   Updated: 2024/11/03 19:41:49 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H

# include "cmd.h"
# include "env.h"
# include "exec_struct.h"
# include "ft_static.h"
# include "history.h"
# include "libft.h"
# include "prompt_struct.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
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

/* _________________________ MANAGE EXTRA UTILS _________________________ */
int				ft_is_ambiguous(char *var_name);
int				ft_manage_rfile(t_rfile *file);
void			ft_printf_env_export(char *str);

/* _________________________ MANAGE UTILS _________________________ */
int				ft_count_arg(char *arg);
int				ft_getlen_word(char *arg);
char			*ft_clear_quote(char *str);
int				ft_extract_arg(char **dest, char *src, int index);
int				ft_update_args(t_cmd *cmd);

/* _________________________ MANAGE ARGS UTILS_________________________ */
int				ft_add_status(char *dest);
int				ft_add_char(char *dest, char c, int i);
int				ft_add_var(char *dest, char *arg, int lenv, int i);
char			*ft_transform_arg(char *arg);
int				ft_transform_args(t_cmd *cmd);

/* _________________________ MANAGE ARGS _________________________ */
int				ft_simple_add(char *dest, char **arg, int i);
int				ft_default_add(char *dest, char **arg, char end, int i);
int				ft_manage_arg_content(char *dest, char *arg);
int				ft_manage_args(t_cmd *cmd);

/* _________________________ EXEC UTILS _________________________ */
char			*ft_search_executable(t_executable exec);
t_executable	ft_init_executable(t_exec_params param);
void			ft_free_executable(t_executable exec);
void			ft_next_cmds(int fd[2], t_exec_params params);
int				ft_check_valid_var(char *var);
char			*subst_home(char *src, t_env *env);
char			*process_hard_links(t_executable *exec);
char			*create_subdir(t_executable *exec, int i);

/* _________________________ EXEC STATUS _________________________ */
int				cmd_found(char *file_exe, int simulate);
int				cmd_executable(char *file_exe, int simulate);
char			*find_exec(t_executable *exec);
int				is_directory(const char *path);

/* _________________________ EXEC _________________________ */
int				ft_exec_cmds(t_exec_params params);

/* _________________________ FD _________________________ */
void			ft_reset_fd(t_executable exec);
int				ft_manage_redirect_file(int fd[2], t_cmd *cmd);
int				ft_pipe_status(int fd[0], int value, int send);
void			ft_error_cd(int type);

int				ft_save_cmd_in_env(t_executable exec);

/* _________________________ FILE_CHECKER _________________________ */
int				ft_file_exist(char *file_name);
int				ft_open(char *file_name, int option);

void			ft_execve(t_executable exec);

#endif
