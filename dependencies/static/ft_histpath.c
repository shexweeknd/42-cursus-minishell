/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_histpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:54:35 by ballain           #+#    #+#             */
/*   Updated: 2024/09/27 12:29:05 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_static.h"

char	*get_histpath(void)
{
	static char	*path = NULL;

	if (!path)
		path = ft_strjoin(get_rootpath(), HIST_PATH);
	return (path);
}
