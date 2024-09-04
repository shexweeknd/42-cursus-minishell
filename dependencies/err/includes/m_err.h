/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_err.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:58:01 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/04 10:59:57 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_ERR_H
# define M_ERR_H

# include "../../cmd/includes/cmd_struct.h"
# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>

t_cmd	*verify_cmds(t_cmd *cmd);

// UTILS FUNCTIONS FOR ERROR HANDLERS
char	*get_link_char(t_link link);

#endif
