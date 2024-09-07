/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:06:19 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/07 09:25:10 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "struct.h"

int	main(int argc, char **argv, char **envp)
{
	char		*prompt;
	t_cmd		*cmd;
	t_hist_elem	*hist;
	t_env		*venv;
	int			id;

	((void)argc, (void)argv);
	venv = ft_getenv(envp);
	hist = get_history("/home/hramaros/Documents/Cursus/Cursus_42/Minishell/dependencies/history/src/.minishell_history.txt");
	while (1)
	{
		prompt = readline("Minishell > ");
		hist = ft_append_hist_elem(hist, ft_strdup(prompt));
		if (!strcmp(prompt, "exit"))
			return (set_history(hist,
					"/home/hramaros/Documents/Cursus/Cursus_42/Minishell/dependencies/history/src/.minishell_history.txt"),
				free(prompt), ft_free_env(venv), 0);
		if (check_syntax_err(prompt))
			continue ;
		cmd = ft_get_cmds(prompt);
		if (free(prompt), !cmd)
			continue ;
		ft_show_cmd(cmd);
		id = fork();
		if (id == 0)
			return (ft_exec_cmds((t_exec_params){0, cmd, cmd, venv, NONE}), 0);
		else
			wait(NULL);
		ft_free_cmds(cmd);
	}
	return (ft_free_env(venv), 0);
}

/*
UTILISATION DE FT_ADD_BACK
===
ft_add_back_((void **)&result, new_history("echo 1", 15), (t_lst_utils){0,
add_back_history, get_next_history
});
*/
