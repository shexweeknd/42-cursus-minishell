/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:22:01 by ballain           #+#    #+#             */
/*   Updated: 2024/08/23 20:27:48 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	_add_next_env(t_env_var *env_var, t_env_var *new)
{
	env_var->next = new;
}

void	*_next_env(void *tmp)
{
	return (((t_env_var *)tmp)->next);
}

t_env_var	*ft_init_var_env(void)
{
	t_env_var	*r_value;

	r_value = (t_env_var *)malloc(sizeof(t_env_var));
	if (!r_value)
		return (NULL);
	r_value->name = NULL;
	r_value->len_name = 0;
	r_value->content = NULL;
	r_value->next = NULL;
	return (r_value);
}

t_env_var	*ft_get_env_var(t_env_var *env_var, char *name)
{
	while (env_var)
	{
		if (ft_strcmp(env_var->name, name) == 0)
			return (env_var);
		env_var = env_var->next;
	}
	return (NULL);
}
