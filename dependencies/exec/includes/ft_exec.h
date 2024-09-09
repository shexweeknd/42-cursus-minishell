/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:58:57 by ballain           #+#    #+#             */
/*   Updated: 2024/09/09 14:16:03 by ballain          ###   ########.fr       */
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
# include "ft_struct_exec.h"

/* _________________________ SRC _________________________ */
void	cd(t_cmd *cmd);
void	echo(t_cmd *cmd);
void	ft_env(t_env *env);
void	export(t_cmd *cmd);
void	pwd(t_cmd *cmd);
void	unset(t_cmd *cmd);
void	ft_exit(void);

int	ft_dqoute_len(char *arg, t_env *env);

/* _________________________ EXEC UTILS _________________________ */
char	*ft_search_executable(t_env *env, char *exe_name);

/* _________________________ EXEC _________________________ */
int		ft_exec_cmds(t_exec_params params);

#endif
