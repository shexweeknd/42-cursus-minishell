#include "minishell.h"

void	ft_lstclear(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->content);
		free(tmp);
	}
}

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
