/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:40:01 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/30 13:39:04 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STATIC_H
# define FT_STATIC_H

# include "env_struct.h"
# include "libft.h"
# include "msh_mac.h"
# include <signal.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/* _________________________ ROOT _________________________ */
char			*get_rootpath(void);
void			set_rootpath(char *new_root_path);

/* _________________________ STATUS _________________________ */
unsigned char	get_status(void);
void			set_status(unsigned char new_status);
int				ft_exit_status(int status);

/* _________________________ SIGNAL _________________________ */
unsigned char	get_sig(void);
void			set_sig(unsigned char new_sig);

/* _________________________ HIST _________________________ */
char			*get_histpath(void);

/* _________________________ HEREDOC _________________________ */
char			*get_hdpath(void);

/* _________________________ STATICS _________________________ */
void			ft_init_paths(char *cwd);
void			ft_clear_paths(void);

/* _________________________ ENV _________________________ */
void			setsenv(t_env *env);
t_env			*getsenv(void);
char			*getvar(char *var_name);
int				getvarlen(char *var_name);

#endif
