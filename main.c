#include "minishell.h"

void	ft_show_list(t_list	*list)
{
	while (list)
	{
		printf("	- %s\n", (char *)list->content);
		list = list->next;
	}
}

int	main(int argc, char const *argv[], char **env)
{
	ft_get_cmds((char *)argv[1]);
	printf("test %d %s %s %s\n", argc, argv[0], *env, getcwd(NULL, 0));
	return (0);
}
