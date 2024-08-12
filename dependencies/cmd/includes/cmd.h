/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:10:41 by ballain           #+#    #+#             */
/*   Updated: 2024/08/12 15:28:21 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "cmd_struct.h"
# include "libft.h"

/* --------------------- UTILS --------------------- */
int			_skip_space(char *str);
int			ft_is_delimiter(const char c);
int			ft_is_cmd_sep(const char c);
int			ft_is_redirect(const char c);

/* --------------------- LIST UTILS --------------------- */
void		ft_add_back_(void **src, void *new, t_list_type type);

/* --------------------- CMD UTILS --------------------- */
int			_get_info(char **str, char *cmd);
int			ft_get_info_len(char *cmd);
int			ft_get_cmd_info(t_cmd *_cmd, char *cmd);

/* --------------------- CMD EXTRA --------------------- */
t_cmd		*_init_cmd(void);
t_io_arg	*_init_io_arg(t_redirect redirect, char *arg);

/* --------------------- CMD EXTRA --------------------- */
t_redirect	ft_get_rtype(char *cmd);
t_link		ft_get_ltype(char *cmd);
int			ft_get_redirect(t_cmd *_cmd, char *cmd);

/* --------------------- CMD --------------------- */
t_cmd		*ft_get_cmds(char *cmd);

#endif