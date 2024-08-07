#ifndef CMD_STRUCT_H
# define CMD_STRUCT_H

typedef enum e_link
{
	NONE,
	PIPE,
	OR,
	AND,
	TMP
}	t_link;

typedef struct s_cmd
{
	char			*name;
	char			*option;
	char			*arg;
	int				in;
	int				out;
	char			*io_arg;
	t_link			link_type;
	struct s_cmd	*next;
}	t_cmd;

#endif