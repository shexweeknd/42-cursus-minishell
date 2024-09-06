/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:21:41 by ballain           #+#    #+#             */
/*   Updated: 2024/09/04 20:18:04 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_STRUCT_H
# define ENV_STRUCT_H

# include "libft.h"

typedef struct s_env
{
	char	**var;
	char	**path;
}	t_env;

#endif
