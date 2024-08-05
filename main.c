#include "minishell.h"

void	ft_show_list(t_list	*list)
{
	while (list)
	{
		printf("	- %s\n", (char *)list->content);
		list = list->next;
	}
}

int main(int argc, char const *argv[], char **env)
{
	t_env	*v_env;

	v_env = ft_get_env(env);
	printf("test %d %s\n", argc, argv[0]);
	// if (argc == 2)
	// {
		while (v_env->var)
		{
			printf("\033[0;4;32m%s :\033[0;0m\n", v_env->var->name);
			ft_show_list(v_env->var->content);
			v_env->var = v_env->var->next;
		}
	// }
	// else
	// {
		// while (*env)
		// {
		// 	printf("%s\n", *env);
		// 	env++;
		// }
	// }
	ft_envclear(v_env);
	return 0;
}


// char	*test;
	// t_env	*v_env;

	// printf("test %d %s\n", argc, argv[0]);
	// v_env = ft_get_env(env);
	// (void)v_env;
	//
	// test = readline("\033[0;32mtest\033[0;0m > ");
	// printf("test value	: [%s]\n", test);