/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:58:57 by ballain           #+#    #+#             */
/*   Updated: 2024/09/02 12:40:29 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "env.h"
# include "cmd.h"

/* _________________________ SRC _________________________ */
void	cd(t_cmd *cmd);
void	echo(t_cmd *cmd);
void	env(t_env_var *venv);
void	export(t_cmd *cmd);
void	pwd(t_cmd *cmd);
void	unset(t_cmd *cmd);
void	ft_exit(t_cmd *cmd);

/* _________________________ EXEC UTILS _________________________ */
char	*ft_search_executable(t_env_var *venv, char *exe_name);

/* _________________________ EXEC _________________________ */
// int		ft_exec_cmd(t_cmd *cmd, t_env_var *venv);
int		ft_exec_cmds(t_cmd *cmd, t_env_var *venv);

/* _________________________ ANALYSE ARG UTILS _________________________ */
int		_skip_venv(char *arg);
int		ft_getlen_venv(char *arg, t_env_var *venv);
int		ft_ltos(char *dest, t_list *src, char sep);
int		ft_new_arg_len(char *arg, t_env_var *venv);
int		ft_manage_venv(char *dest, char *src, t_env_var *venv, int len);

/* _________________________ ANALYSE ARG _________________________ */
int		ft_analyse_args(t_cmd *cmd, t_env_var *venv);

#endif
