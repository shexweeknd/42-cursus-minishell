/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hdpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:54:28 by ballain           #+#    #+#             */
/*   Updated: 2024/09/27 12:29:06 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_static.h"

char	*get_hdpath(void)
{
	static char	*path = NULL;

	if (!path)
		path = ft_strjoin(get_rootpath(), HD_PATH);
	return (path);
}
