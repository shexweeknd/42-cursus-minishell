/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:53:01 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/07 14:32:21 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HD_H
# define HD_H

# include "ft_static.h"
# include "hd_struct.h"
# include "libft.h"
# include "m_err.h"
# include "msh_mac.h"
# include "sig.h"

// MAIN HD_CREATE FUNC
void	process_hd(t_eofs *eofs);
t_hd	*hd_cmd(char cmd, char *eof);

// HD_UTILS
int		ft_write_hd(int fd, char *line);
size_t	fullfill_fd(int fd, char *eof);
char	*get_hd(int fd, size_t size);
int		_hd_occ(char *line);
char	*get_eof(char *line);
t_eofs	*append_eofs(t_eofs *eofs, char *eof);

// PRE_PARSING FUNC
int		hd_check_syntax_err(char *prompt);
int		skip_until_hd(char *line);
int		skip_hd_eof(char *line);

// CLEANUP FUNC
void	free_eofs(t_eofs *eofs);
void	recurse_free_hd(t_hd *hd);
void	recurse_close_hd(t_hd *hd);

// SIG FUNC
void	hd_prompt_sig_handler(int signal);

// DEBUG FUNC
void	print_hd(t_hd *hd);

#endif