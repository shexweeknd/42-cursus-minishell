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
	t_list	*lst;
	// ft_get_cmd("test -t ./file");
	lst = ft_lstnew("test");
	if (!lst)
		return (0);
	ft_add_back_((void **)(&lst), ft_lstnew("test 2"), LIST);
	ft_show_list(lst);
	printf("test %d %s %s %s\n", argc, argv[0], *env, getcwd(NULL, 0));
	chdir("/goinfre/ballain/Minishell/lol");
	printf("current	: [%s]\n", getcwd(NULL, 0));
	return (0);
}


// char *line;
    // while ((line = readline("Enter something: ")) != NULL) {
    //     if (*line) { // Si la ligne n'est pas vide
    //         add_history(line);
    //     }
    //     printf("You entered: %s\n", line);
	// 	rl_clear_history();
	// 	if (ft_strcmp(line, "end"))
    //     {
	// 		free(line);
	// 		break ;
	// 	}
    //     free(line);
    // }
    // rl_clear_history();
	// rl_cleanup_after_signal();

// t_env_var	*v_env;
	// t_list		*content;

	// v_env = ft_get_env(env);
	// (void)v_env;
	// content = (t_list *)ft_get_env_var(v_env, "PATH", 1);
	// ft_show_list(content);
	
	// ft_envclear(v_env);

// printf("FIND TEST	: [%s]\n", ((t_env_var *)ft_get_env_var(v_env, "PATH", 0))->name);
	// if (argc == 2)
	// {
		// while (v_env)
		// {
		// 	printf("\033[0;4;32m%s :\033[0;0m\n", v_env->name);
		// 	ft_show_list(v_env->content);
		// 	v_env = v_env->next;
		// }
	// }
	// else
	// {
		// while (*env)
		// {
		// 	printf("%s\n", *env);
		// 	env++;
		// }
	// }


// char	*test;
// t_env	*v_env;

// printf("test %d %s\n", argc, argv[0]);
// v_env = ft_get_env(env);
// (void)v_env;
//
// test = readline("\033[0;32mtest\033[0;0m > ");
// printf("test value	: [%s]\n", test);