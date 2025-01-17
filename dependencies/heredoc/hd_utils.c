/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:53:46 by hramaros          #+#    #+#             */
/*   Updated: 2024/11/03 20:24:46 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hd.h"

int	skip_until_hd(char *line)
{
	int	result;

	result = 0;
	while (line[result])
	{
		if (line[result] == '"')
			result += skip_until(&line[result], '"');
		else if (line[result] == '\'')
			result += skip_until(&line[result], '\'');
		if (!ft_strncmp(&line[result], "<<", 2))
			break ;
		if (line[result])
			result++;
	}
	return (result);
}

int	skip_hd_eof(char *line)
{
	int	result;

	result = 0;
	if (!ft_strncmp(line, "<<", 2))
		result += 2;
	while (ft_isspace(line[result]))
		result++;
	while (!ft_isspace(line[result]))
	{
		if (line[result] == '"')
			result += skip_until(&line[result], '"');
		else if (line[result] == '\'')
			result += skip_until(&line[result], '\'');
		if (!line[result] || ft_is_delimiter(line[result])
			|| ft_is_redirect(line[result]))
			break ;
		result++;
	}
	return (result);
}

int	_hd_occ(char *line)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	while (i < ft_strlen(line) && line[i])
	{
		if (line[i] == '<' && line[i + 1] == '<')
			result++;
		i++;
	}
	return (result);
}

static int	ft_write_var_hd(int fd, char *line, int lenv)
{
	int		len;
	char	*tmp;
	char	*var;

	tmp = ft_substr(line, 0, lenv);
	var = getvar(tmp);
	len = ft_strlen(var);
	if (var)
		write(fd, var, len);
	if (tmp)
		free(tmp);
	return (len);
}

int	ft_write_hd(int fd, char *line)
{
	int		len;
	int		lenv;
	char	*status;

	status = ft_itoa(get_status());
	len = 0;
	while (line && *line)
	{
		if (*line == '$' && ft_isvar(line + 1))
		{
			lenv = ft_lenvar_name(++line);
			if (*line == '?')
				len += (write(fd, status, ft_strlen(status)),
						ft_strlen(status));
			else
				len += ft_write_var_hd(fd, line, lenv);
			line += lenv;
		}
		else
			len += (write(fd, line++, 1), 1);
	}
	return (free(status), len);
}
