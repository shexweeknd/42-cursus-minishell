/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:22:01 by ballain           #+#    #+#             */
/*   Updated: 2024/08/15 10:03:28 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	_add_next_env(t_env_var *env_var, t_env_var *new)
{
	if (!env_var || new)
		return ;
	env_var->next = new;
}

void	*_next_env(void *tmp)
{
	return (((t_env_var *)tmp)->next);
}

int	ft_getstr(char **dest, char *str, char delimiter)
{
	char	*tmp;
	int		len;

	if (!(*str) || !dest)
		return (0);
	tmp = ft_strchr(str, delimiter);
	if (!tmp)
		len = ft_strlen(str);
	else
		len = tmp - str;
	if (!len)
		return (0);
	*dest = ft_substr(str, 0, len);
	if (!(*dest))
		return (0);
	if (!tmp)
		len++;
	return (len);
}

t_env_var	*ft_init_var_env(void)
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

void	*ft_get_env_var(t_env_var *env_var, char *name, int type)
{
	while (env_var)
	{
		if (ft_strcmp(env_var->name, name) == 0)
		{
			if (type == 0)
				return (env_var);
			return (env_var->content);
		}
		env_var = env_var->next;
	}
	return (NULL);
}

