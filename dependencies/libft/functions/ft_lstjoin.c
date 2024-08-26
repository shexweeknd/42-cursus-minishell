#include "libft.h"

int	ft_lst_content_len(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len += ft_strlen((char *)lst->content);
		lst = lst->next;
	}
	return (len);
}

char	*ft_lstjoin(t_list *lst, char sep)
{
	int		i;
	int		len;
	char	*tmp;
	char	*r_value;

	i = 0;
	len = (ft_lstsize(lst) - 1) + ft_lst_content_len(lst) + 1;
	r_value = (char *)malloc(sizeof(char) * len);
	if (!r_value)
		return (NULL);
	while (lst)
	{
		tmp = (char *)lst->content;
		while (*tmp)
			r_value[i++] = *(tmp++);
		if (lst->next)
			r_value[i++] = sep;
		lst = lst->next;
	}
	r_value[i] = '\0';
	return (r_value);
}
