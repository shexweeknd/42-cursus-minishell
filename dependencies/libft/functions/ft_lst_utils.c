/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:59:20 by ballain           #+#    #+#             */
/*   Updated: 2024/08/16 10:31:31 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*_get_next(void *tmp, t_lst_utils utils)
{
	if (utils._next)
		return (utils._next(tmp, utils.type));
	return ((void *)((t_list *)tmp)->next);
}

void	_loop(void **src, t_lst_utils utils)
{
	void	*tmp;
	void	*func_param;

	tmp = *src;
	while (tmp)
	{
		func_param = tmp;
		tmp = _get_next(tmp, utils);
		if (utils._do)
			utils._do(func_param, utils.type);
	}
}

void	ft_add_back_(void **src, void *new, t_lst_utils utils)
{
	void	*tmp;

	if (!src || !new)
		return ;
	if (!utils._do)
	{
		ft_lstadd_back((t_list **)src, new);
		return ;
	}
	tmp = *src;
	while (tmp && _get_next(tmp, utils))
		tmp = _get_next(tmp, utils);
	if (!tmp)
		*src = new;
	else
		utils._do(tmp, new, utils.type);
}

void	ft_add_front_(void **src, void *new, t_lst_utils utils)
{
	void	*tmp;

	if (!src || !new)
		return ;
	tmp = *src;
	*src = new;
	if (utils._do)
		utils._do(new, tmp, utils.type);
	else
		ft_lstadd_back((t_list **)src, tmp);
}
