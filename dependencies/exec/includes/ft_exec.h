/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:58:57 by ballain           #+#    #+#             */
/*   Updated: 2024/08/20 08:04:24 by ballain          ###   ########.fr       */
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
# include "ft_exec_struct.h"

/* _________________________ SRC _________________________ */
void	cd(t_cmd *cmd);
void	echo(t_cmd *cmd);
void	env(t_cmd *cmd);
void	export(t_cmd *cmd);
void	pwd(t_cmd *cmd);
void	unset(t_cmd *cmd);
void	ft_exit(t_cmd *cmd);

/* _________________________ EXEC UTILS _________________________ */
char	*ft_search_executable(t_env_var *venv, char *exe_name);
int		ft_exec_cmd(t_cmd *cmd, t_env_var *venv, char **env);
int		ft_exec_cmds(t_cmd *cmd, t_env_var *venv, char **env);

#endif
