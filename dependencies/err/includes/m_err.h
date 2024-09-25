/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_err.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:58:01 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/25 19:21:14 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_ERR_H
# define M_ERR_H

# include "libft.h"
# include "ft_status.h"
# include "hd.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>

int		check_syntax_err(char *prompt, int with_hd);

int		check_op_at_start(char *prompt);
int		chev_check(char *prompt, int *flag, int chev_type, int lvl);
int		op_check(char *prompt, int *flag, int chev_type, int lvl);

// UTILS FUNCTIONS FOR PARSING ERROR
void	display_unexpected_token(char *token);
int		is_unexpected(char *prompt, int lvl);


#endif
