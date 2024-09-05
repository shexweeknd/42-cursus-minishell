/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate_contents.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:26:35 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/05 08:46:04 by ballain          ###   ########.fr       */
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

char	*ft_getvar(t_env *env, char *var_name)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	tmp = NULL;
	len = ft_strlen(var_name);
	while (env->var[i])
	{
		tmp = env->var[i];
		if (ft_strncmp(env->var[i], var_name, len) == 0)
			break ;
		i++;
	}
	while (tmp && *tmp && *tmp != '=')
		tmp++;
	if (tmp && *tmp == '=')
		tmp++;
	if (tmp && *tmp)
		return (tmp);
	return (NULL);
}
