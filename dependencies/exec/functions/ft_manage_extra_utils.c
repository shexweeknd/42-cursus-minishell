/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_extra_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:40:14 by ballain           #+#    #+#             */
/*   Updated: 2024/11/03 19:40:13 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_is_ambiguous(char *var_name)
{
	if (var_name && *var_name == '$' \
	&& *(var_name + 1) && !getvar(var_name + 1))
	{
		ft_perror_fd(2, (char *[]){MSH_LOG, ": ", \
		var_name, ": ambiguous redirect", NULL});
		return (1);
	}
	return (0);
}

int	ft_manage_rfile(t_rfile *file)
{
	char	*tmp;

	while (file)
	{
		if (ft_is_ambiguous(file->args))
			return (0);
		tmp = ft_clear_quote(ft_transform_arg(file->args));
		file->args = (free(file->args), tmp);
		file = file->next;
	}
	return (1);
}

void	ft_printf_env_export(char *str)
{
	write(1, "export ", 7);
	while (str && *str && *str != '=')
		write(1, str++, 1);
	if (str && *str && *str == '=' && str++)
		write(1, "=", 1);
	write(1, "\"", 1);
	if (str && *str)
	{
		while (str && *str && *str)
			write(1, str++, 1);
	}
	write(1, "\"\n", 2);
}
