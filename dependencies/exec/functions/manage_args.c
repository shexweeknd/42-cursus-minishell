/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:14:57 by hramaros          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/17 10:40:50 by ballain          ###   ########.fr       */
=======
/*   Updated: 2024/09/22 13:33:45 by ballain          ###   ########.fr       */
>>>>>>> 1d7cd3b (correction rebase)
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_getlen_args(char *arg, t_env *env)
{
	int		len;
	char	quote;
	char	*end_quote;

	len = 0;
	while (arg && *arg)
	{
		quote = ft_is_quote(*arg);
		if (quote)
		{
			end_quote = ft_strchr(++arg, quote);
			if (end_quote && *end_quote == '"')
				arg = ((len += ft_dqoute_len(&arg, env, "\"")), ++end_quote);
			else if (end_quote && *end_quote == '\'')
				arg = ((len += end_quote - arg), ++end_quote);
			else
				len += 1;
		}
		else
			len += ft_dqoute_len(&arg, env, "\"'");
	}
	return (len);
}

void	ft_addnew_args(char *dest, char *arg, t_env *env)
{
	int		i;
	char	quote;
	char	*end_quote;

	i = 0;
	while (arg && *arg)
	{
		quote = ft_is_quote(*arg);
		if (quote)
		{
			end_quote = ft_strchr(++arg, quote);
			if (end_quote && *end_quote == '"')
				arg = ((i += ft_dquote_add((dest + i), &arg, env, "\"")), \
					++end_quote);
			else if (end_quote && *end_quote == '\'')
			{
				ft_strlcpy(dest + i, arg, end_quote - arg + 1);
				arg = ((i += end_quote - arg), end_quote + 1);
			}
			else
				*(dest + i++) = quote;
		}
		else
			i += ft_dquote_add((dest + i), &arg, env, "\"'");
	}
}

void	*ft_manage_args(t_cmd *cmd, t_env *env)
{
	int		i;
	int		new_len;
	char	*tmp;
	t_cmd	*tmp_cmd;

	tmp_cmd = cmd;
	while (tmp_cmd)
	{
		i = -1;
		while (tmp_cmd->args[++i])
		{
			new_len = ft_getlen_args(tmp_cmd->args[i], env);
			if (new_len != (int)ft_strlen(tmp_cmd->args[i]))
			{
				tmp = tmp_cmd->args[i];
				tmp_cmd->args[i] = (char *)malloc(sizeof(char) * (new_len + 1));
				if (!tmp_cmd->args[i])
					return (NULL);
				ft_bzero(tmp_cmd->args[i], new_len + 1);
				(ft_addnew_args(tmp_cmd->args[i], tmp, env), free(tmp));
			}
		}
		tmp_cmd = tmp_cmd->next;
	}
	return (cmd);
}
