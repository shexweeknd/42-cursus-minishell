#include "minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

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

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!(*str))
		return (-1);
	while (*str)
	{
		if (*str == c)
			return (i);
		str++;
		i++;
	}
	return (-1);
}

t_list	*ft_lstnew()
{
	t_list	*r_value;

	r_value = (t_list *)malloc(sizeof(t_list));
	if (!r_value)
		return (NULL);
	r_value->content = NULL;
	r_value->next = NULL;
	return (r_value);
}

t_list	*ft_lstnewc(int len)
{
	t_list	*r_value;

	r_value = (t_list *)malloc(sizeof(t_list));
	if (!r_value)
		return (NULL);
	r_value->content = (char *)malloc(sizeof(char) * (++len));
	if (!r_value->content)
		return (NULL);
	r_value->next = NULL;
	return (r_value);
}

t_list	*ft_get_var_env_content(char *var_env)
{
	t_list	*r_value;
	char	*tmp;
	int		len;

	while (*var_env && *(var_env++) != '=')
		;
	tmp = var_env;
	while (*var_env)
	{
		len = ft_strchr(var_env, ':');
		if (len == -1)
			len = ft_strlen(var_env);
		if (len == 0)
			break ;
		while (*var_env)
		{

			var_env++;
		}
	}
}

t_env_var	*ft_init_env_var()
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

t_env	*ft_get_env(char **env)
{
	t_env	*v_env;

	v_env = (t_env *)malloc(sizeof(t_env));
	if (!v_env)
		return (NULL);
	v_env->var = ft_init_env_var();
	if (!v_env->var)
		return (NULL);
	v_env->first = v_env->var;
	while (*env)
	{
		v_env->var->name = ft_get_var_env_name(*env);
		if (*(env + 1))
		{
			v_env->var->next = ft_init_env_var();
			if (!v_env->var->next)
				return (NULL);
		}
		else
			v_env->var->next = NULL;
		v_env->var = v_env->var->next;
		env++;
	}
	v_env->var = v_env->first;
	return (v_env);
}
