#include "env.h"

char	*ft_get_var_env_name(char *var_env)
{
	char	*tmp;
	char	*var_env_name;
	int		i;
	int		len;

	i = 0;
	len = 0;
	tmp = var_env;
	while (*tmp && *(tmp++) != '=')
		len++;
	var_env_name = (char *)malloc(sizeof(char) + (++len));
	if (!var_env_name)
		return (NULL);
	while (*var_env && *var_env != '=')
		var_env_name[i++] = *(var_env++);
	var_env_name[i] = '\0';
	return (var_env_name);
}

t_list	*ft_get_var_env_content(char *var_env)
{
	t_list	*r_value;
	t_list	*r_tmp;
	int		i;

	while (*var_env && *(var_env++) != '=')
		;
	r_value = ft_lstnew(NULL);
	if (!r_value)
		return (NULL);
	r_tmp = r_value;
	while (r_tmp && *var_env)
	{
		i = 0;
		r_tmp->content = ft_init_var_env_content(var_env);
		if (!r_tmp->content)
			break ;
		while (*var_env && *var_env != ':')
			((char *)r_tmp->content)[i++] = *(var_env++);
		((char *)r_tmp->content)[i] = '\0';
		if (*var_env == ':')
			var_env++;
		if (*var_env)
			r_tmp->next = ft_lstnew(NULL);
		else
			r_tmp->next = NULL;
		r_tmp = r_tmp->next;
	}
	return (r_value);
}

t_env_var	*ft_get_env(char **env)
{
	printf("sdfsdf");
	printf("ENV TEST	: [%s] \n", *env);
	// t_env_var	*env_var;
	// t_env_var	*r_value;

	// env_var = ft_init_var_env();
	// if (!env_var)
	// 	return (NULL);
	// r_value = env_var;
	// while (*env)
	// {
	// 	env_var->name = ft_get_var_env_name(*env);
	// 	env_var->content = ft_get_var_env_content(*env);
	// 	printf("%s\n", env_var->name);
	// 	if (*(env++))
	// 	{
	// 		env_var->next = ft_init_var_env();
	// 		if (!env_var->next)
	// 			return (NULL);
	// 	}
	// 	else
	// 		env_var->next = NULL;
	// 	env_var = env_var->next;
	// }
	return (NULL);
}

// int main(int argc, char const *argv[], char **env)
// {
// 	(void)argc;
// 	(void)argv;
// 	ft_get_env(env);
// 	return 0;
// }

