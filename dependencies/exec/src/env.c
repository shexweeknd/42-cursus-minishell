#include "ft_exec.h"

void	print_content(t_list *content)
{
	printf("%s", (char *)content->content);
	if (content->next)
		printf(":");
}

void	print_env(t_env_var *venv)
{
	printf("%s=", venv->name);
	_loop((void **)&venv->content, (t_lst_utils){0, print_content, NULL});
	printf("\n");
}

void	env(t_env_var *venv)
{
	_loop((void **)&venv, (t_lst_utils){0, print_env, _next_env});
}