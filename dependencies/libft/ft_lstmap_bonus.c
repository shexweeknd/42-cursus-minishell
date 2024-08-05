/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:43:16 by ballain           #+#    #+#             */
/*   Updated: 2024/02/29 17:58:09 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*r_value;
	t_list	*tmp;

	r_value = (t_list *)malloc(sizeof(t_list));
	tmp = r_value;
	if (!r_value || !lst)
		return (0);
	while (lst)
	{
		tmp->content = (*f)(lst->content);
		if (!lst->next)
		{
			tmp->next = NULL;
			break ;
		}
		tmp->next = (t_list *)malloc(sizeof(t_list));
		if (!tmp->next)
		{
			ft_lstclear(&r_value, del);
			return (0);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (r_value);
}
