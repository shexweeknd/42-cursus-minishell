#include "ft_exec.h"

char	*ft_join_path(char *path, char *sep, char *name)
{
	int		i;
	int		len;
	char	*r_value;

	if (!path)
		path = ".";
	if (!sep)
		sep = "/";
	if (!name)
		return (NULL);
	i = 0;
	len = ft_strlen(path) + ft_strlen(path) + ft_strlen(path) + 1;
	r_value = (char *)malloc(sizeof(char) * len);
	if (!r_value)
		return (NULL);
	while (*path)
		r_value[i++] = *(path++);
	while (*sep)
		r_value[i++] = *(sep++);
	while (*name)
		r_value[i++] = *(name++);
	r_value[i] = '\0';
	return (r_value);
}

char	*ft_search_executable(t_env_var *venv, char *exe_name)
{
	t_env_var	*path;
	t_list		*tmp_paths;
	char		*tmp;

	path = ft_get_env_var(venv, "PATH");
	if (!path)
		return (NULL);
	tmp_paths = path->content;
	while (tmp_paths)
	{
		tmp = ft_join_path(tmp_paths->content, "/", exe_name);
		if (!tmp)
			return (NULL);
		if (access(tmp, F_OK | X_OK) == 0)
			return (tmp);
		free(tmp);
		tmp_paths = tmp_paths->next;
	}
	return (NULL);
}