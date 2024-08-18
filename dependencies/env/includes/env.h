/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:21:45 by ballain           #+#    #+#             */
/*   Updated: 2024/08/18 11:29:54 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include "libft.h"
# include "env_struct.h"

void		_add_next_env(t_env_var *env_var, t_env_var *new);
void		*_next_env(void *tmp);

int			ft_getstr(char **dest, char *str, char delimiter);
t_env_var	*ft_init_var_env(void);
t_env_var	*ft_get_env(char **env);
t_env_var	*ft_get_env_var(t_env_var *env_var, char *name);
void		ft_free_env(t_env_var *env_var);

#endif
