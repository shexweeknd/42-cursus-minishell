/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:21:45 by ballain           #+#    #+#             */
/*   Updated: 2024/08/13 10:23:51 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "env_struct.h"
# include "libft.h"
# include <stdlib.h>

t_env_var	*ft_init_var_env(void);
char		*ft_init_var_env_content(char *var_env);
t_env_var	*ft_get_env(char **env);
void		*ft_get_env_var(t_env_var *env_var, char *name, int type);
void		ft_envclear(t_env_var *env_var);

#endif
