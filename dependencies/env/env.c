/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:22:05 by ballain           #+#    #+#             */
/*   Updated: 2024/08/15 10:05:46 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
		if (*var_env == ':' && *(++var_env))
			r_tmp->next = ft_lstnew(NULL);
		r_tmp = r_tmp->next;
	}
	return (r_value);
}

void	ft_get_venv_content(t_list **lst, char *var_env)
{
	char		*tmp;

	while (*var_env)
	{
		tmp = NULL;
		var_env += ft_getstr(&tmp, var_env, ':');
		if (!tmp)
			return ;
		ft_add_back_((void **)lst, ft_lstnew(tmp), (t_lst_utils){0});
		var_env++;
	}
}

t_env_var	*ft_get_env(char **env)
{
	t_env_var	*env_var;
	t_env_var	*r_value;

	env_var = ft_init_var_env();
	if (!env_var)
		return (NULL);
	r_value = env_var;
	while (*env)
	{
		// env_var->name = ft_get_var_env_name(*env);
		*env += ft_getstr(&env_var->name, *env, '=');
		// printf("NAME	: [%s]\n", env_var->name);
		ft_get_venv_content(&env_var->content, *env);
		if (*(++env))
		{
			env_var->next = ft_init_var_env();
			if (!env_var->next)
				return (NULL);
		}
		else
			env_var->next = NULL;
		env_var = env_var->next;
	}
	return (r_value);
}
