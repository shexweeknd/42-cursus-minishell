/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:21:45 by ballain           #+#    #+#             */
/*   Updated: 2024/09/04 20:17:35 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "env_struct.h"
# include "libft.h"
# include <stdlib.h>

int			ft_getlen_env(char **envp);
int			ft_getlen_path(char *path);
char		**ft_split_path(char *src);
t_env		*ft_getenv(char **envp);
void		ft_free_env(t_env *env);

#endif
