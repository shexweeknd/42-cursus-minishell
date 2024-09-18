/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:42:52 by ballain           #+#    #+#             */
/*   Updated: 2024/09/18 18:42:52 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_replace(char *src, char *to_find, char *replace, int all)
{
	int		ret_len;
	int		tof_len;
	int		nb;
	char	*found;

	nb = 0;
	ret_len = ft_strlen(src);
	tof_len = ft_strlen(to_find);
	found = ft_strnstr(src, to_find, ft_strlen(src));
	if (found && !all)
		nb++;
	while (found && all)
	{
		nb++;
		src = found + tof_len;
		found = ft_strnstr(src, to_find, ft_strlen(src));
	}
	return (ret_len - (tof_len * nb) + (ft_strlen(replace) * nb));
}

char	*ft_str_replace(char *src, char *to_find, char *replace, int all)
{
	int		i;
	int		len;
	int		count;
	int		tof_len;
	char	*r_value;

	i = ((tof_len = ft_strlen(to_find)), (count = 0), 0);
	len = ft_strlen_replace(src, to_find, replace, all);
	r_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!r_value)
		return (NULL);
	while (i < len)
	{
		if (((!all && count < 1) || all) && !ft_strncmp(src, to_find, tof_len))
		{
			src += ((count += 1), tof_len);
			i += ft_strlcpy(r_value + i, replace, ft_strlen(replace) + 1);
		}
		else
			r_value[i++] = *(src++);
	}
	r_value[i] = '\0';
	return (r_value);
}
