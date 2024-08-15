/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:21:55 by ballain           #+#    #+#             */
/*   Updated: 2024/08/15 11:24:40 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	_free_env(t_env_var *env_var)
{
	free(env_var->name);
	ft_lstclear(&env_var->content, free);
	free(env_var);
}

void	ft_free_env(t_env_var *env_var)
{
	_loop((void **)&env_var, (t_lst_utils){0, _free_env, _next_env});
}
