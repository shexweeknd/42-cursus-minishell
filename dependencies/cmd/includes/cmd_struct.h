/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:10:45 by ballain           #+#    #+#             */
/*   Updated: 2024/09/11 16:10:28 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_STRUCT_H
# define CMD_STRUCT_H

# include "libft.h"

typedef enum e_list_type
{
	CMD,
	R_FILE
}	t_list_type;

typedef enum e_link
{
	NONE,
	PIPE,
	BG,
	OR,
	AND
}	t_link;

typedef enum e_redirect
{
	NO,
	IN_1,
	IN_2,
	OUT_1,
	OUT_2
}	t_redirect;

typedef struct s_rfile
{
	int				option;
	char			*args;
	struct s_rfile	*next;
}	t_rfile;

typedef struct s_cmd
{
	char			**args;
	int				nb_arg;
	t_rfile			*file_in;
	t_rfile			*file_out;
	t_link			l_type;
	struct s_cmd	*next;
}	t_cmd;

#endif
