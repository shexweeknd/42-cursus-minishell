#include "cmd.h"

void	ft_show_cmd(t_cmd *cmd)
{
	printf("\033[0;4;32mCMD	:\033[0;0m\n");
	printf(" name	: [%s]\n", cmd->name);
	printf(" option	: [%s]\n", cmd->option);
	printf(" arg	: [%s]\n", cmd->arg);
	printf(" in	: [%d]\n", cmd->in);
	printf(" out	: [%d]\n", cmd->out);
	printf(" io_arg	: [%s]\n", cmd->io_arg);
	if (cmd->link_type == NONE)
		printf(" l_type	: [NONE]\n");
	if (cmd->link_type == PIPE)
		printf(" l_type	: [PIPE]\n");
	if (cmd->link_type == OR)
		printf(" l_type	: [OR]\n");
	if (cmd->link_type == AND)
		printf(" l_type	: [AND]]\n");
}

int	ft_get_info_len(char *cmd)
{
	int	i;

	i = 0;
	while (*cmd)
	{
		if (ft_is_cmd_sep(*cmd))
			return (i);
		i++;
		cmd++;
	}
	return (i);
}

t_cmd	*ft_cmd(char *cmd)
{
	(void)cmd;
	return (NULL);
}
