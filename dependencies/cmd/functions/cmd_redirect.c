#include "cmd.h"

t_redirect	ft_get_rtype(char *cmd)
{
	if (!cmd)
		return (NONE);
	if (*cmd == '<' && cmd++)
	{
		if (*cmd == '<')
			return (IN_2);
		return (IN_2);
	}
	if (*cmd == '>' && cmd++)
	{
		if (*cmd == '>')
			return (OUT_2);
		return (OUT_1);
	}
	return (NONE);
}

void	ft_get_redirect(t_cmd *_cmd, char *cmd)
{
	int	len;
	
	if ((*cmd == '<' || *cmd == '>'))
	{
		_cmd->io_arg->redirect = ft_get_rtype(cmd);
		if (_cmd->io_arg->redirect == IN_1 || _cmd->io_arg->redirect == OUT_1)
			cmd++;
		else if (_cmd->io_arg->redirect == IN_2 || _cmd->io_arg->redirect == OUT_2)
			cmd += 2;
		if (_cmd->io_arg->redirect != NONE)
		{
			len = ft_get_info_len(cmd);
			_cmd->io_arg->arg = ft_substr(cmd, 0, len);
			cmd += len;
		}
	}
}
