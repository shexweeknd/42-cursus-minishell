/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:10:45 by ballain           #+#    #+#             */
/*   Updated: 2024/08/18 19:30:39 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_STRUCT_H
# define CMD_STRUCT_H

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
	char			*file_in;
	char			*file_out;
	char			*file_append;
	char			*heredoc;
	t_link			link_type;
	struct s_cmd	*next;
}	t_cmd;

#endif
