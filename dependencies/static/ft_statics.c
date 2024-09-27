#include "ft_static.h"

void	ft_init_paths(char *cwd)
{
	set_rootpath(cwd);
	get_hdpath();
	get_histpath();
}

void	ft_clear_paths()
{
	free(get_hdpath());
	free(get_histpath());
}