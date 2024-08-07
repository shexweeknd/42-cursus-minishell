#include "cmd.h"

int	ft_is_cmd_sep(const int c)
{
	return (ft_isspace(c) || c == '|' || c == '&');
}

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

void	ft_add_cmd_info(t_cmd *cmd, void *value, int type)
{
	if (type == 0)
		cmd->name = (char *)value;
	if (type == 1)
		cmd->option = (char *)value;
	if (type == 2)
		cmd->arg = (char *)value;
	if (type == 3)
		cmd->in = *((int *)value);
	if (type == 4)
		cmd->out = *((int *)value);
	if (type == 5)
		cmd->io_arg = (char *)value;
	if (type == 6)
		cmd->link_type = *((int *)value);
}

