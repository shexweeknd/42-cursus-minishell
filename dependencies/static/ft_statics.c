/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_statics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:43:27 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/27 18:19:50 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_static.h"

void	ft_init_paths(char *cwd)
{
	set_rootpath(cwd);
	get_hdpath();
	get_histpath();
}

void	ft_clear_paths(void)
{
	free(get_hdpath());
	free(get_histpath());
}
