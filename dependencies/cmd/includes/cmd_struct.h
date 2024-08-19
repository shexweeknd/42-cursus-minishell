/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:10:45 by ballain           #+#    #+#             */
/*   Updated: 2024/08/19 10:24:49 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_STRUCT_H
# define CMD_STRUCT_H

# include "libft.h"

typedef enum e_list_type
{
	CMD,
	IO_ARG
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

typedef struct s_cmd
{
	char			**args;
	t_list			*file_in;
	t_list			*file_out;
	t_list			*file_append;
	t_list			*heredoc;
	t_link			link_type;
	struct s_cmd	*next;
}	t_cmd;

#endif
