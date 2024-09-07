#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	((void)argc, (void)argv);
	char *prompt;
	t_cmd *cmd;
	t_hist_elem *hist;
	t_env *venv;

	venv = ft_getenv(envp);
	hist = get_history(HIST_PATH);
	while (1)
	{
		prompt = readline(MSH_NAME);
		hist = ft_append_hist_elem(hist, ft_strdup(prompt));
		if (strcmp(prompt, "exit") == 0)
			return (set_history(hist,
					HIST_PATH),
				free(prompt), ft_free_env(venv), 0);
		if (check_syntax_err(prompt))
			continue ;
		cmd = ft_get_cmds(prompt);
		if (free(prompt), !cmd)
			continue ;
		// ft_show_cmd(cmd);
		cmd = (ft_exec_cmds((t_exec_params){0, cmd, cmd, venv, cmd->link_type}),
				ft_free_cmds(cmd), NULL);
	}
	return (ft_free_env(venv), 0);
}
