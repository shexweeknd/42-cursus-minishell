/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hdpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:54:28 by ballain           #+#    #+#             */
/*   Updated: 2024/09/27 11:54:42 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_static.h"

static char	*hdpath(char *new_path, int save)
{
	static char	*path = NULL;

	if (save)
		path = new_path;
	return (path);
}

char	*get_hdpath(void)
{
	return (hdpath(NULL, 0));
}

void	set_hdpath(char *new_root_path)
{
	hdpath(new_root_path, 1);
}
