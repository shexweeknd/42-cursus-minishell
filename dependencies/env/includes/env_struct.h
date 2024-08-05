#ifndef ENV_STRUCT_H
# define ENV_STRUCT_H

# include "libft.h"

typedef struct s_env_var
{
	char				*name;
	t_list				*content;
	struct s_env_var	*next;
}	t_env_var;

typedef struct s_env
{
	t_env_var	*first;
	t_env_var	*var;
	char		*(*find_str);
	t_list		*(*get_content);
	void		*(*show);
}	t_env;

#endif