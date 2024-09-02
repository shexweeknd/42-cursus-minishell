/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:21:45 by ballain           #+#    #+#             */
/*   Updated: 2024/09/02 15:26:15 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "env_struct.h"
# include "libft.h"
# include <stdlib.h>

void		_add_next_env(t_env_var *env_var, t_env_var *new);
void		*_next_env(void *tmp);

int			ft_getstr(char **dest, char *str, char delimiter);
t_env_var	*ft_init_var_env(void);
t_env_var	*ft_get_env(char **env);
t_env_var	*ft_get_env_var(t_env_var *env_var, char *name);
void		ft_free_env(t_env_var *env_var);
char		*concatenate_content(t_list *content);

#endif
