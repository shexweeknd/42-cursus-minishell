/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:10:45 by ballain           #+#    #+#             */
/*   Updated: 2024/08/16 23:32:46 by ballain          ###   ########.fr       */
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

typedef struct s_io_arg
{
	t_redirect		redirect;
	char			*arg;
	struct s_io_arg	*next;
}	t_io_arg;

typedef struct s_cmd
{
	char			**args;
	t_io_arg		*io_arg;
	t_link			link_type;
	struct s_cmd	*next;
}	t_cmd;

#endif
