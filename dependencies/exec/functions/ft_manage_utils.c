/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:43:35 by ballain           #+#    #+#             */
/*   Updated: 2024/11/03 20:27:20 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_count_arg(char *arg)
{
	int		nb_arg;
	char	stop;

	nb_arg = 0;
	while (arg && *arg)
	{
		while (arg && *arg && ft_isspace(*arg))
			arg++;
		if (arg && *arg)
			nb_arg++;
		while (arg && *arg && !ft_isspace(*arg))
		{
			stop = 0;
			if (arg && ft_is_quote(*arg))
				stop = *(arg++);
			while (arg && *arg && ((stop && *arg != stop) || \
				(!stop && !ft_isspace(*arg))))
				arg++;
			if (stop && arg && *arg && *arg == stop)
				arg++;
		}
	}
	return (nb_arg);
}

int	ft_getlen_word(char *arg)
{
	int		len;
	char	stop;

	len = 0;
	while (arg && *arg && !ft_isspace(*arg))
	{
		stop = 0;
		if (arg && ft_is_quote(*arg))
			len += ((stop = *(arg++)), 1);
		while (arg && *arg && ((stop && *arg != stop) || \
			(!stop && !ft_isspace(*arg) && !ft_is_quote(*arg))))
			len += ((arg += 1), 1);
		if (arg && *arg && stop != 0 && *arg == stop)
			len += ((arg += 1), 1);
	}
	return (len);
}

char	*ft_clear_quote(char *str)
{
	int		i;
	int		j;
	char	*r_value;
	char	stop;

	r_value = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!r_value)
		return (NULL);
	i = 0;
	j = 0;
	while (str && str[i])
	{
		stop = 0;
		if (str && ft_is_quote(str[i]))
			stop = str[i++];
		while (str && str[i] && ((stop && str[i] != stop) || \
			(!stop && !ft_is_quote(str[i]))))
			r_value[j++] = str[i++];
		if (str && str[i] && stop != 0 && str[i] == stop)
			i++;
	}
	r_value[j] = 0;
	if (str)
		free(str);
	return (r_value);
}

int	ft_extract_arg(char **dest, char *src, int index)
{
	int		len;
	char	*tmp;

	while (src && *src)
	{
		while (src && *src && ft_isspace(*src))
			src++;
		if (!*src)
			return (index);
		len = ft_getlen_word(src);
		if (!len)
			return (0);
		src += ((tmp = ft_substr(src, 0, len)), len);
		dest[index++] = ft_clear_quote(tmp);
	}
	return (index);
}

int	ft_update_args(t_cmd *cmd)
{
	int		i;
	int		j;
	int		nb_narg;
	char	**_args;

	nb_narg = ft_transform_args(cmd);
	_args = (char **)malloc(sizeof(char *) * (nb_narg + 1));
	if (!_args)
		return (0);
	i = ((j = 0), 0);
	while (cmd && cmd->args && cmd->args[i])
	{
		nb_narg = ft_count_arg(cmd->args[i]);
		if (nb_narg == 0)
			i++;
		else if (nb_narg == 1)
			_args[j++] = ft_clear_quote(ft_strdup(cmd->args[i++]));
		else
			j = ft_extract_arg(_args, cmd->args[i++], j);
	}
	_args[j] = NULL;
	cmd->args = (ft_free_args(cmd), _args);
	return (j);
}
