/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:11:02 by ballain           #+#    #+#             */
/*   Updated: 2024/09/10 13:22:24 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int	ft_get_args_len(char *cmd)
{
	int	i;

	i = 0;
	while (*cmd && !ft_is_delimiter(*cmd))
	{
		if (ft_is_redirect(*cmd))
		{
			while (*cmd && ft_is_redirect(*cmd))
				cmd++;
			cmd += _skip_space(cmd);
			while (*cmd && !ft_is_cmd_sep(*cmd))
				cmd++;
		}
		cmd += _get_info(NULL, cmd);
		i++;
	}
	return (i);
}

int	ft_get_info_len(char *cmd)
{
	int		i;
	char	*end;
	char	quote;

	i = 0;
	while (*cmd && !ft_is_cmd_sep(*cmd))
	{
		end = 0;
		quote = ft_is_quote(*cmd);
		if (quote)
		{
			end = ft_strchr((cmd + 1), quote);
			if (end)
			{
				i += (++end) - cmd;
				cmd = end;
			}
		}
		if (!end)
		{
			cmd++;
			i++;
		}
	}
	return (i);
}

int	_get_info(char **str, char *cmd)
{
	int	len;
	int	i;

	if (!cmd)
		return (0);
	i = _skip_space(cmd);
	len = ft_get_info_len(cmd + i);
	if (len && str && *str == NULL)
		*str = ft_substr(cmd + i, 0, len);
	i += _skip_space(cmd + i + len);
	return (i + len);
}
