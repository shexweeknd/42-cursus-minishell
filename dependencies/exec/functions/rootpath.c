/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rootpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:00:26 by ballain           #+#    #+#             */
/*   Updated: 2024/09/24 16:00:30 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

static char	*rootpath(char *new_path, int save)
{
	static char	*path = NULL;

	if (save)
		path = new_path;
	return (path);
}

char	*get_rootpath(void)
{
	return (rootpath(NULL, 0));
}

void	set_rootpath(char *new_root_path)
{
	rootpath(new_root_path, 1);
}
