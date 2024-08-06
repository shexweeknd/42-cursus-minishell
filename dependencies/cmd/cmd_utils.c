#include "cmd.h"

void	ft_add_back_cmd(t_cmd **cmd, t_cmd *new_cmd)
{
	t_cmd	*tmp;

	if (!cmd || !new_cmd)
		return ;
	tmp = *cmd;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!tmp)
		*cmd = new_cmd;
	else
		tmp->next = new_cmd;
}

