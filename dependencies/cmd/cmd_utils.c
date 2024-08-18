/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:11:02 by ballain           #+#    #+#             */
/*   Updated: 2024/08/18 18:52:17 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int	ft_get_args_len(char *cmd)
{
	int	i;

	i = 0;
	while (*cmd && !ft_is_delimiter(*cmd) && !ft_is_redirect(*cmd))
	{
		cmd += _get_info(NULL, cmd);
		i++;
	}
	return (i);
}

int	ft_get_info_len(char *cmd)
{
	int		i;
	char	end;

	i = 0;
	if (!cmd)
		return (0);
	end = ft_is_quote(*cmd);
	if (end != '\0')
		cmd++;
	while (*cmd && *cmd != end)
	{
		if ((end == '\0' && ft_is_cmd_sep(*cmd)) || ft_is_redirect(*cmd))
			return (i);
		i++;
		cmd++;
	}
	return (i);
}

int	_get_info(char **str, char *cmd)
{
	int	len;
	int	i;
	int	is_arg;

	if (!cmd)
		return (0);
	is_arg = 0;
	i = _skip_space(cmd);
	len = ft_get_info_len(cmd + i);
	if (ft_is_quote(*cmd))
	{
		i++;
		is_arg = 1;
	}
	if (len && str && *str == NULL)
		*str = ft_substr(cmd + i, 0, len);
	if (is_arg)
		i++;
	i += _skip_space(cmd + i + len);
	return (i + len);
}
