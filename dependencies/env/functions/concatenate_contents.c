/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate_contents.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:26:35 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/18 17:05:01 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "env_struct.h"

int	get_content_size(t_list *content)
{
	int	result;

	result = 0;
	while (content)
	{
		result++;
		content = content->next;
	}
	return (result);
}

int	env_content_len(t_list *content)
{
	int	result;

	result = 0;
	while (content)
	{
		result += ft_strlen(content->content);
		content = content->next;
	}
	return (result);
}

char	*concatenate_content(t_list *content)
{
	char	*result;
	char	*temp;

	result = NULL;
	while (content)
	{
		temp = ft_strjoin(result, content->content);
		free(result);
		content = content->next;
		if (!content)
			break ;
		result = ft_strjoin(temp, ":");
	}
	return (result);
}

char	*ft_search_var(t_env *env, char *var_name)
{
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(var_name);
	while (env->var[++i])
	{
		if (ft_strncmp(env->var[i], var_name, len) == 0 && \
			env->var[i][len] == '=')
			break ;
	}
	return (env->var[i]);
}

char	*ft_getvar(t_env *env, char *var_name)
{
	int		i;
	char	*var;

	i = 0;
	var = ft_search_var(env, var_name);
	if (var)
	{
		while (var[i++] != '=')
			;
		if (var + i)
			return (var + i);
	}
	return (NULL);
}
