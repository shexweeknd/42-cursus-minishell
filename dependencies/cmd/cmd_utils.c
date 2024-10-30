/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:11:02 by ballain           #+#    #+#             */
/*   Updated: 2024/10/30 09:55:53 by ballain          ###   ########.fr       */
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
	while (*cmd && !ft_is_cmd_sep(*cmd) && !ft_is_redirect(*cmd))
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

char	*ft_get_hdvalue(t_cmd *_cmd, t_hd *hd)
{
	int				fd;
	char			*buffer;
	char			*tmp_name;
	static t_cmd	*tmp = NULL;
	static int		i = 0;

	if (tmp != _cmd)
		tmp = (i++, _cmd);
	tmp_name = ft_init_tmp_name(i);
	fd = open(tmp_name, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (hd->size));
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, hd->size);
	read(hd->fd[0], buffer, hd->size);
	write(fd, buffer, hd->size);
	(close(hd->fd[0]), close(fd), free(buffer));
	if (!hd || !hd->next)
		i = 1;
	return (tmp_name);
}

int	_get_hdinfo(t_cmd *_cmd, char **str, char *cmd)
{
	int			i;
	int			j;
	int			len;
	t_hd		*hd;
	static int	i_hd = 0;

	if (!cmd)
		return (0);
	j = i_hd;
	hd = hd_cmd('g', NULL);
	while (j--)
		hd = hd->next;
	i = _skip_space(cmd);
	len = ft_get_info_len(cmd + i);
	if (len && str && *str == NULL)
		*str = ft_get_hdvalue(_cmd, hd);
	i += _skip_space(cmd + i + len);
	i_hd++;
	if (!hd || !hd->next)
		i_hd = 0;
	return (i + len);
}
