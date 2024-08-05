#include "env.h"

t_env_var	*ft_init_var_env()
{
	t_env_var	*r_value;

	r_value = (t_env_var *)malloc(sizeof(t_env_var));
	if (!r_value)
		return (NULL);
	r_value->name = NULL;
	r_value->content = NULL;
	r_value->next = NULL;
	return (r_value);
}

char	*ft_init_var_env_content(char *var_env)
{
	char	*r_value;
	char	*tmp;
	int		len;

	tmp = ft_strchr(var_env, ':');
	if (!tmp)
		len = ft_strlen(var_env) + 1;
	else
		len = tmp - var_env;
	if (len == 0)
		return (NULL);
	r_value = (char *)malloc(sizeof(char) + len);
	if (!r_value)
		return (NULL);
	return (r_value);
}

// int	ft_get_var_env_content(t_list *list, char *var_env)
// {
// 	(void)list;
// 	(void)var_env;
// 	return (0);
// }
