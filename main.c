#include "minishell.h"

int main(int argc, char const *argv[], char **env)
{
	t_env	*v_env;

	v_env = ft_get_env(env);
	printf("test %d %s\n", argc, argv[0]);
	// if (argc == 2)
	// {
		while (v_env->var)
		{
			printf("%s\n", v_env->var->name);
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