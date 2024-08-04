#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include "env_struct.h"

/** LIBFT */
int		ft_strlen(char *str);
int		ft_strchr(char *str, char c);
t_list	*ft_lstnew();
int		ft_strncpy(char	*str, char *cpy, int nb);

t_env_var	*ft_init_var_env();
char		*ft_init_var_env_content(char *var_env);

#endif