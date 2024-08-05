/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:45:38 by ballain           #+#    #+#             */
/*   Updated: 2024/02/29 18:27:52 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_alloc_rvalue(char const *s, char c, int *nb_w)
{
	int		i;
	int		can_count_word;
	char	**r_value;

	i = 0;
	can_count_word = 1;
	r_value = NULL;
	while (s[i] != '\0')
	{
		if (s[i] != c && can_count_word)
		{
			can_count_word = 0;
			*nb_w += 1;
		}
		if (s[i] == c)
			can_count_word = 1;
		i++;
	}
	*nb_w += 1;
	r_value = (char **)malloc(sizeof(char *) * (*nb_w));
	if (!r_value)
		return (0);
	return (r_value);
}

int	ft_iandl(const char *s, char c, int *i, int *len)
{
	int	tmp;

	tmp = 0;
	while (s[*i] == c)
		*i += 1;
	tmp = *i;
	while (s[*i] != c)
	{
		if (s[*i] == '\0')
			break ;
		*i += 1;
		*len += 1;
	}
	return (tmp);
}

int	ft_fill_content(char **r_value, char const *s, char c)
{
	int	i;
	int	id;
	int	tmp;
	int	len;

	i = 0;
	id = 0;
	tmp = 0;
	len = 0;
	while (s[i] != '\0')
	{
		len = 0;
		tmp = ft_iandl(s, c, &i, &len);
		if (len != 0)
		{
			r_value[id] = ft_substr(s, tmp, len);
			if (!r_value[id])
				return (0);
			id++;
		}
	}
	r_value[id] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		nb_w;
	char	**r_value;

	nb_w = 0;
	r_value = ft_alloc_rvalue(s, c, &nb_w);
	if (!r_value)
		return (0);
	if (nb_w == 0)
	{
		r_value[0] = NULL;
		return (r_value);
	}
	ft_fill_content(r_value, s, c);
	return (r_value);
}
