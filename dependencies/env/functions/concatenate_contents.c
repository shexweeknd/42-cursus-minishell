/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate_contents.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:26:35 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/02 15:47:00 by hramaros         ###   ########.fr       */
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
