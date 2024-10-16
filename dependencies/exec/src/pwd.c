/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:17:42 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/16 17:15:10 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

void	ft_pwd_error(int type, char value)
{
	char	tmp[2];

	tmp[0] = value;
	tmp[1] = 0;
	if (type == 1)
		ft_perror_fd(2, (char *[]){MSH_LOG, ": pwd: -", \
		tmp, ": invalid option", NULL});
	else if (type == 2)
		ft_perror_fd(1, (char *[]){"pwd: usage: pwd [-LP]", NULL});
}

static int	ft_check_pwd_error(char *arg)
{
	char	*tmp;
	int		error;

	error = 0;
	tmp = NULL;
	if (!arg)
		return (error);
	if (*arg == '"')
		tmp = ft_strtrim(arg, "\"");
	else if (*arg == '\'')
		tmp = ft_strtrim(arg, "'");
	else
		tmp = ft_strdup(arg);
	if (*tmp && *tmp == '-')
	{
		if (*(tmp + 1) && (*(tmp + 1) != 'L' && *(tmp + 1) != 'P'))
		{
			error = 1;
			ft_pwd_error(1, *(tmp + 1));
			ft_pwd_error(2, 0);
		}
	}
	if (tmp)
		free(tmp);
	return (error);
}

int	pwd(t_executable exec)
{
	char	*cwd;

	if (!ft_check_pwd_error(exec.cmd->args[1]))
	{
		cwd = getcwd(NULL, 0);
		if (!cwd)
			return (ft_perror_fd(2, (char *[]){"pwd: error retrieving current", \
			" directory: getcwd: cannot access parent directories: No such ", \
			"file or directory", NULL}), 1);
		else
			(printf("%s\n", cwd), free(cwd));
	}
	return (0);
}
