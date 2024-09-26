/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_descriptor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:17:58 by ballain           #+#    #+#             */
/*   Updated: 2024/09/26 13:58:46 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

void	ft_reset_fd(t_executable exec)
{
	dup2(exec.o_fd[0], STDIN_FILENO);
	dup2(exec.o_fd[1], STDOUT_FILENO);
}

void	ft_manage_redirect_file(int fd[2], t_cmd *cmd)
{
	t_rfile	*tmp_in;
	t_rfile	*tmp_out;

	tmp_in = cmd->file_in;
	while (tmp_in && tmp_in->next)
		tmp_in = tmp_in->next;
	tmp_out = cmd->file_out;
	while (tmp_out && tmp_out->next)
		tmp_out = (close(open(tmp_out->args, tmp_out->option)), tmp_out->next);
	if (tmp_in)
		fd[0] = (close(fd[0]), open(tmp_in->args, tmp_in->option));
	else
		fd[0] = (close(fd[0]), -1);
	if (tmp_out)
		fd[1] = (close(fd[1]), open(tmp_out->args, tmp_out->option));
	else if (!(cmd->next && cmd->l_type == PIPE))
		fd[1] = (close(fd[1]), -1);
	if (fd[0] != -1)
		(dup2(fd[0], STDIN_FILENO), close(fd[0]));
	if (fd[1] != -1)
		(dup2(fd[1], STDOUT_FILENO), close(fd[1]));
}

int	ft_pipe_status(int fd[0], int value, int send)
{
	if (send)
	{
		close(fd[0]);
		if (write(fd[1], &value, sizeof(int)) == -1)
			return (close(fd[1]), 1);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		if (read(fd[0], &value, sizeof(int)) == -1)
			return (close(fd[0]), 1);
		close(fd[0]);
		return (value);
	}
	return (0);
}
