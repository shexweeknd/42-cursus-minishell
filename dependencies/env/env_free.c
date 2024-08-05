#include "minishell.h"

void	ft_envclear(t_env *env)
{
	t_env_var	*var;
	t_env_var	*tmp;

	var = env->var;
	while (var)
	{
		tmp = var;
		var = var->next;
		free(tmp->name);
		ft_lstclear(tmp->content);
		free(tmp);
	}
	free(env);
}
