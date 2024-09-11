/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:55:43 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/11 14:40:35 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*prompt;
	t_cmd		*cmd;
	t_hist_elem	*hist;
	t_env		*venv;

	hist = get_history(HIST_PATH);
	venv = ft_getenv(envp);
	while (1)
	{
		prompt = get_prompt(MSH_NAME, venv);
		if (prompt == NULL)
			continue ;
		hist = ft_append_hist_elem(hist, ft_strdup(prompt));
		if (strcmp(prompt, "exit") == 0)
			return (set_history(hist, HIST_PATH), free(prompt),
				ft_free_env(venv), 0);
		cmd = ft_get_cmds(prompt);
		if (free(prompt), !cmd)
			continue ;
		ft_show_cmd(cmd);
		cmd = (ft_exec_cmds((t_exec_params){0, cmd, cmd, venv, cmd->link_type}),
				ft_free_cmds(cmd), NULL);
	}
	return (ft_free_env(venv), 0);
}
