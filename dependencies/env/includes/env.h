/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:21:45 by ballain           #+#    #+#             */
/*   Updated: 2024/09/19 12:32:20 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "env_struct.h"
# include "libft.h"
# include <stdlib.h>

int		ft_getlen_path(char *path);
char	**ft_split_path(char *src);
t_env	*ft_getenv(char **envp);
char	*ft_search_var(t_env *env, char *var_name);
char	*ft_getvar(t_env *env, char *var_name);
char	*ft_setvar(t_env *env, char *var_name, char *str);
void	ft_free_env(t_env *env);

#endif
