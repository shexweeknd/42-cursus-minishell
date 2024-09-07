/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:36:33 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/07 11:56:54 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "../../env/includes/env.h"
# include "../../env/includes/env_struct.h"
# include "../../err/includes/m_err.h"
# include "libft.h"

int		is_pipe_at_end(char *prompt);
int		is_uncomplete_prompt(char *prompt);

char	*get_col_ps_two(t_env *env);
char	*ft_join_prompt(char *prompt, t_env *env);
char	*get_prompt(char *msh_name, t_env *env);

#endif