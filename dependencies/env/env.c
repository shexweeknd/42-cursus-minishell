/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:22:05 by ballain           #+#    #+#             */
/*   Updated: 2024/08/23 16:50:37 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
	if (tmp)
		len++;
	return (len);
}

void	ft_get_venv_content(t_list **lst, char *var_env)
{
	char		*tmp;

	while (*var_env)
	{
		tmp = NULL;
		var_env += ft_getstr(&tmp, var_env, ':');
		while (*var_env && *var_env == ':')
			var_env++;
		if (!tmp)
			return ;
		ft_add_back_((void **)lst, ft_lstnew(tmp), (t_lst_utils){0});
	}
}

t_env_var	*ft_get_env(char **env)
{
	t_env_var	*tmp;
	t_env_var	*r_value;
	t_lst_utils	utils;

	r_value = NULL;
	utils = (t_lst_utils){0, _add_next_env, _next_env};
	while (*env)
	{
		tmp = ft_init_var_env();
		if (!tmp)
			return (NULL);
		tmp->len_name = ft_getstr(&tmp->name, *env, '=');
		*env += tmp->len_name;
		ft_get_venv_content(&tmp->content, *env);
		ft_add_back_((void **)&r_value, tmp, utils);
		env++;
	}
	return (r_value);
}
