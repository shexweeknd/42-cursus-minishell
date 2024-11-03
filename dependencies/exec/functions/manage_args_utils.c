/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:24:30 by ballain           #+#    #+#             */
/*   Updated: 2024/11/03 18:40:51 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_add_status(char *dest)
{
	int	status;
	int	len;
	int	r_len;

	status = get_status();
	len = ft_nblen(status);
	r_len = len;
	while (len)
	{
		*(dest + (--len)) = (status % 10) + '0';
		status /= 10;
	}
	return (r_len);
}

int	ft_add_char(char *dest, char c, int i)
{
	if (dest)
	{
		dest += i;
		return ((*dest = c), 1);
	}
	return (0);
}

int	ft_add_var(char *dest, char *arg, int lenv, int i)
{
	char	*var_content;
	char	*tmp;
	int		len;

	len = 0;
	if (!lenv)
		return (0);
	if (*arg == '?' && dest)
		return (ft_add_status(dest + i));
	if (*arg == '?' && !dest)
		return ((len += ft_nblen(get_status())), len);
	tmp = ft_substr(arg, 0, lenv);
	var_content = getvar(tmp);
	if (var_content && dest)
		len = ft_strlcpy(dest + i, var_content, ft_strlen(var_content) + 1);
	if (var_content && !dest)
		len = ft_strlen(var_content);
	if (tmp)
		tmp = (free(tmp), NULL);
	return (len);
}

char	*ft_transform_arg(char *arg)
{
	int		len;
	char	*r_value;

	len = ft_manage_arg_content(NULL, arg);
	r_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!r_value)
		return (NULL);
	r_value[ft_manage_arg_content(r_value, arg)] = 0;
	return (r_value);
}

int	ft_transform_args(t_cmd *cmd)
{
	int		i;
	int		nb_narg;
	char	*tmp;

	i = 0;
	nb_narg = 0;
	while (cmd && cmd->args && cmd->args[i])
	{
		tmp = ft_transform_arg(cmd->args[i]);
		if (!tmp)
			return (0);
		cmd->args[i] = (free(cmd->args[i]), tmp);
		nb_narg += ft_count_arg(tmp);
		i++;
	}
	return (nb_narg);
}
