#include "minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!(*str))
		return (-1);
	while (*str)
	{
		if (*str == c)
			return (i);
		str++;
		i++;
	}
	return (-1);
}

t_list	*ft_lstnew()
{
	t_list	*r_value;

	r_value = (t_list *)malloc(sizeof(t_list));
	if (!r_value)
		return (NULL);
	r_value->content = NULL;
	r_value->next = NULL;
	return (r_value);
}

int	ft_strncpy(char	*str, char *cpy, int nb)
{
	int	i;

	i = 0;
	if (nb || !(*str))
		return (0);
	while (i < nb && *str && *(cpy + i))
		cpy[i++] = *(str++);
	cpy[i] = '\0';
	return (i);
}
