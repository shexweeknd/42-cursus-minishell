/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:30:45 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/02 13:35:13 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIFORM_H
# define UNIFORM_H

# include "../../cmd/includes/cmd.h"
# include "../../env/includes/env.h"

t_cmd	*uniform_cmds(t_cmd *cmds, t_env_var *venv);

#endif
