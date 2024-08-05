#ifndef ENV_STRUCT_H
# define ENV_STRUCT_H

# include "libft.h"

typedef struct s_env_var
{
	char				*name;
	t_list				*content;
	struct s_env_var	*next;
}	t_env_var;

#endif