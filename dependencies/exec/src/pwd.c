#include "ft_exec.h"

void	pwd(t_cmd *cmd)
{
	char	*cwd;
	char	*tmp;
	char	*to_free;
	int		has_error;

	printf("PWD HERE\n");
	tmp = NULL;
	to_free = NULL;
	has_error = 0;
	if (cmd->args[1])
	{
		if (*cmd->args[1] == '"')
			tmp = ft_strtrim(cmd->args[1], "\"");
		else if (*cmd->args[1] == '\'')
			tmp = ft_strtrim(cmd->args[1], "'");
		else
			tmp = cmd->args[1];
		if (*tmp && *tmp == '-')
		{
			to_free = tmp;
			tmp++;
			if (*tmp && (*tmp != 'L' || *tmp != 'P'))
			{
				has_error = 1;
				printf("bash: pwd: -%c: invalid option\npwd: usage: pwd [-LP]\n", *tmp);
			}
		}
		if (to_free && to_free != cmd->args[1])
			free(to_free);
	}
	if (!has_error)
	{
		cwd = getcwd(NULL, 0);
		(printf("%s\n", cwd), free(cmd));
	}
}
