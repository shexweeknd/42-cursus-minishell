/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:21:41 by ballain           #+#    #+#             */
/*   Updated: 2024/08/05 19:21:42 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_STRUCT_H
# define ENV_STRUCT_H

# include "libft.h"

typedef struct s_env_var
{
	char				*name;
	t_list				*content;
	struct s_env_var	*next;
}	t_env_var;

#endif