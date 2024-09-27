/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_histpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:54:35 by ballain           #+#    #+#             */
/*   Updated: 2024/09/27 11:54:39 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_static.h"

static char	*histpath(char *new_path, int save)
{
	static char	*path = NULL;

	if (save)
		path = new_path;
	return (path);
}

char	*get_histpath(void)
{
	return (histpath(NULL, 0));
}

void	set_histpath(char *new_root_path)
{
	histpath(new_root_path, 1);
}
