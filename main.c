#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>

void	ft_show_list(t_list *list)
{
	while (list)
	{
		printf("	- %s\n", (char *)list->content);
		list = list->next;
	}
}

int	main(int argc, char const **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	set_history();
	return (0);
}
