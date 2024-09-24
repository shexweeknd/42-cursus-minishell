/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:35:14 by ballain           #+#    #+#             */
/*   Updated: 2024/09/24 14:53:21 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_env(t_executable exec)
{
	int	i;

	i = 0;
	while (exec.env->var[i])
		printf("%s\n", exec.env->var[i++]);
	return (0);
}
