#include "cmd.h"

void	*_next(void *value, t_list_type type)
{
	if (type == CMD)
		return (((t_cmd *)value)->next);
	if (type == LIST)
		return (((t_list *)value)->next);
	return (value);
}

void	_add_next(void *value, void *next, t_list_type type)
{
	if (type == CMD)
		((t_cmd *)value)->next = (t_cmd *)next;
	if (type == LIST)
		((t_list *)value)->next = (t_list *)next;
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
