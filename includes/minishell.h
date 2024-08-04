#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "struct.h"
# include "env.h"

t_env	*ft_get_env(char **env);
void	ft_envclear(t_env *env);

#endif