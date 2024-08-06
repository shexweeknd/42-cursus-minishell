/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:21:45 by ballain           #+#    #+#             */
/*   Updated: 2024/08/06 14:16:35 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include "env_struct.h"
# include "libft.h"

t_env_var	*ft_init_var_env(void);
char		*ft_init_var_env_content(char *var_env);
t_env_var	*ft_get_env(char **env);
void		*ft_get_env_var(t_env_var *env_var, char *name, int type);
void		ft_envclear(t_env_var *env_var);

#endif
