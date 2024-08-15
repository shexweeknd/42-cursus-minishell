/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:10:41 by ballain           #+#    #+#             */
/*   Updated: 2024/08/15 13:32:24 by ballain          ###   ########.fr       */
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
int			ft_is_delimiter(const char c);
int			ft_is_cmd_sep(const char c);
int			ft_is_redirect(const char c);

/* --------------------- CMD UTILS --------------------- */
void		ft_show_ltype(t_link link_type);
void		ft_show_redirection(t_redirect redirect);
int			ft_get_info_len(char *cmd);
int			ft_get_cmd_info(t_cmd *_cmd, char *cmd);
int			_get_info(char **str, char *cmd);

/* --------------------- CMD EXTRA UTILS --------------------- */
int			_skip_space(char *str);
t_cmd		*_init_cmd(void);
t_io_arg	*_init_io_arg(t_redirect redirect, char *arg);
void		*_next_cmd(void *value, t_list_type type);
void		_add_next_cmd(void *value, void *next, t_list_type type);

/* --------------------- CMD EXTRA --------------------- */
t_redirect	ft_get_rtype(char *cmd);
t_link		ft_get_ltype(char *cmd);
int			ft_get_redirect(t_cmd *_cmd, char *cmd);

/* --------------------- CMD --------------------- */
void		ft_show_cmd(t_cmd *cmd);
t_cmd		*ft_get_cmds(char *cmd);

/* --------------------- CMD FREE --------------------- */
void		_free(void *value, t_list_type type);
void		ft_free_cmds(t_cmd *cmd);

#endif