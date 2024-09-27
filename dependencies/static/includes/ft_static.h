/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:40:01 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/27 11:56:24 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STATIC_H
# define FT_STATIC_H

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
int		get_status(void);
void	set_status(int new_status);
void	ft_print_status(int status);


#endif
