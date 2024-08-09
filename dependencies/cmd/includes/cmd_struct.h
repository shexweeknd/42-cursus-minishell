#ifndef CMD_STRUCT_H
# define CMD_STRUCT_H

typedef enum e_list_type
{
	CMD,
	LIST
}	t_list_type;

typedef enum e_link
{
	NONE,
	PIPE,
	OR,
	AND,
}	t_link;

typedef enum e_redirect
{
	NONE,
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
	char			*name;
	char			*option;
	char			*arg;
	t_io_arg		*io_arg;
	t_link			link_type;
	struct s_cmd	*next;
}	t_cmd;

#endif
