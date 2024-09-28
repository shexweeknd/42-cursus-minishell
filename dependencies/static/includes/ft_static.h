/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:40:01 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/28 07:33:27 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STATIC_H
# define FT_STATIC_H

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
void			ft_print_status(unsigned char status);

/* _________________________ HIST _________________________ */
char			*get_histpath(void);

/* _________________________ HEREDOC _________________________ */
char			*get_hdpath(void);

/* _________________________ STATICS _________________________ */
void			ft_init_paths(char *cwd);
void			ft_clear_paths(void);

#endif
