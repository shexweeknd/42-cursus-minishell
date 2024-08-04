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
	int		len;

	len = ft_strchr(var_env, ':');
	if (len == -1)
		len = ft_strlen(var_env) + 1;
	if (len == 0)
		return (NULL);
	r_value = (char *)malloc(sizeof(char) + len);
	if (!r_value)
		return (NULL);
	return (r_value);
}

int	ft_get_var_env_content()
{

}
