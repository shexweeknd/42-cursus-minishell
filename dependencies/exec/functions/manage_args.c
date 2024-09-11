/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:14:57 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/11 16:15:58 by hramaros         ###   ########.fr       */
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
				len++;
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
				arg = ((i += ft_dquote_add((dest + i), &arg, env, "\"")),
						++end_quote);
			else if (end_quote && *end_quote == '\'')
			{
				while (arg && *arg && *arg != *end_quote)
					*(dest + i++) = *(arg++);
				arg++;
			}
			else
				i++;
		}
		else
			i += ft_dquote_add((dest + i), &arg, env, "\"'");
	}
	*(dest + i) = 0;
}

void	*ft_manage_args(t_cmd *cmd, t_env *env)
{
	int		i;
	int		len;
	int		new_len;
	char	*tmp;

	i = 0;
	while (cmd->args[i])
	{
		len = ft_strlen(cmd->args[i]);
		new_len = ft_getlen_args(cmd->args[i], env);
		if (len != new_len)
		{
			tmp = cmd->args[i];
			cmd->args[i] = (char *)malloc(sizeof(char) * (new_len + 1));
			if (!cmd->args[i])
				return (NULL);
			ft_bzero(cmd->args[i], new_len);
			(ft_addnew_args(cmd->args[i], tmp, env), free(tmp));
		}
		i++;
	}
	return (NULL);
}
