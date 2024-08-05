#include "env.h"

static void	ft_del_value(void *value)
{
	free((char *)value);
}

void	ft_envclear(t_env_var *env_var)
{
	t_env_var	*tmp;

	while (env_var)
	{
		tmp = env_var;
		env_var = env_var->next;
		free(tmp->name);
		ft_lstclear(&tmp->content, ft_del_value);
	}
}
