#include "minishell.h"

int main(int argc, char const *argv[])
{
	char	*test;

	printf("test %d %s\n", argc, argv[0]);
	test = readline("\033[0;32mtest\033[0;0m >");
	printf("test value	: [%s]\n", test);
	return 0;
}
