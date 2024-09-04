/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_err.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:58:01 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/04 14:58:38 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_ERR_H
# define M_ERR_H

# include "../../cmd/includes/cmd_struct.h"
# include "libft.h"
# include "m_err_struct.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>

int		check_syntax_err(char *prompt);

// UTILS FUNCTIONS FOR ERROR HANDLERS
char	*get_link_char(t_link link);
int		is_unexpected_at_start(char *cmd);
// int		is_unexpected_at_middle(char *cmd);

#endif
