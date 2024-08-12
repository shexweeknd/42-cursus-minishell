/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:10:33 by ballain           #+#    #+#             */
/*   Updated: 2024/08/12 18:33:11 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	*_next(void *value, t_list_type type)
{
	if (type == CMD)
		return (((t_cmd *)value)->next);
	if (type == LIST)
		return (((t_list *)value)->next);
	if (type == IO_ARG)
		return (((t_io_arg *)value)->next);
	return (value);
}

void	_add_next(void *value, void *next, t_list_type type)
{
	if (type == CMD)
		((t_cmd *)value)->next = (t_cmd *)next;
	if (type == LIST)
		((t_list *)value)->next = (t_list *)next;
	if (type == IO_ARG)
		((t_io_arg *)value)->next = (t_io_arg *)next;
}

void	_loop(void **src, void (*_do)(void *, t_list_type), t_list_type type)
{
	void	*tmp;
	void	*func_param;

	tmp = *src;
	while (tmp)
	{
		func_param = tmp;
		tmp = _next(tmp, type);
		if (_do)
			_do(func_param, type);
	}	
}

void	ft_add_back_(void **src, void *new, t_list_type type)
{
	void	*tmp;

	if (!src || !new)
		return ;
	tmp = *src;
	while (tmp && _next(tmp, type))
		tmp = _next(tmp, type);
	if (!tmp)
		*src = new;
	else
		_add_next(tmp, new, type);
}
