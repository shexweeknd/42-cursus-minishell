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
	t_env_var	*v_env;

	printf("test 2\n");
	v_env = ft_get_env(env);
	(void)v_env;
	printf("test %d %s\n", argc, argv[0]);
	// if (argc == 2)
	// {
		while (v_env)
		{
			printf("\033[0;4;32m%s :\033[0;0m\n", v_env->name);
			ft_show_list(v_env->content);
			v_env = v_env->next;
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
	// ft_envclear(v_env);
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