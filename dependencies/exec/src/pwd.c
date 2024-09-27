/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:17:42 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/27 08:32:29 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

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
			ft_printf_fd("%s: pwd: -%c: invalid option\n", 2, MSH_LOG, *tmp);
			ft_printf_fd("pwd: usage: pwd [-LP]\n");
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
		(printf("%s\n", cwd), free(cwd));
	}
	return (0);
}
