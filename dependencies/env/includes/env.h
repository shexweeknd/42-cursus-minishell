#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include "env_struct.h"
# include "libft.h"

t_env_var	*ft_init_var_env();
char		*ft_init_var_env_content(char *var_env);
t_env_var	*ft_get_env(char **env);
void		ft_envclear(t_env_var *env_var);

#endif
