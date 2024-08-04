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
	r_value = ft_lstnew();
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
			r_tmp->next = ft_lstnew();
		else
			r_tmp->next = NULL;
		r_tmp = r_tmp->next;
	}
	return (r_value);
}

t_env	*ft_get_env(char **env)
{
	t_env	*v_env;

	v_env = (t_env *)malloc(sizeof(t_env));
	if (!v_env)
		return (NULL);
	v_env->var = ft_init_var_env();
	if (!v_env->var)
		return (NULL);
	v_env->first = v_env->var;
	while (*env)
	{
		v_env->var->name = ft_get_var_env_name(*env);
		v_env->var->content = ft_get_var_env_content(*env);
		if (*(env++))
		{
			v_env->var->next = ft_init_var_env();
			if (!v_env->var->next)
				return (NULL);
		}
		else
			v_env->var->next = NULL;
		v_env->var = v_env->var->next;
	}
	v_env->var = v_env->first;
	return (v_env);
}
