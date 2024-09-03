#ifndef FT_STRUCT_EXEC_H
# define FT_STRUCT_EXEC_H

#include "cmd.h"
#include "env.h"

typedef struct s_exec_prams
{
	int			read_fd;
	t_cmd		*cmd;
	t_env_var	*venv;
	t_link		link_type;
}	t_exec_params;


#endif