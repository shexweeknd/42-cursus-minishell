/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:14:57 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/28 13:46:57 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int	ft_dqoute_len(char **arg, t_env *env, char *stop)
{
	int		len;
	int		lenv;

	len = 0;
	while (**arg && !ft_strchr(stop, **arg))
	{
		lenv = ft_isvar(*arg);
		if (lenv)
		{
			if ((*arg)++ && (!**arg || \
				(!ft_strcmp(stop, "\"") && ft_strchr(stop, **arg))))
				return ((len += lenv), len);
			if (ft_strchr(stop, **arg))
				return (len);
			if (**arg == '?')
				len += ((*arg += 1), ft_nblen(get_status()));
			else
				*arg += ((len += ft_lenvar(*arg, env, lenv)), lenv);
		}
		else
			len += ((*arg += 1), 1);
	}
	return (len);
}

int	ft_dquote_add(char *dest, char **arg, t_env *env, char *stop)
{
	int		i;
	int		lenv;

	i = 0;
	while (**arg && ft_strchr(stop, **arg) == NULL)
	{
		lenv = ft_isvar(*arg);
		if (lenv)
		{
			(*arg)++;
			if (!**arg || (!ft_strcmp(stop, "\"") && ft_strchr(stop, **arg)))
				return ((dest[i] = '$'), (i += lenv), i);
			else if (ft_strchr(stop, **arg))
				break ;
			else if (**arg == '?')
				i += ((*arg += 1), ft_add_status(dest));
			else
				*arg += ((i += ft_cpvar((dest + i), *arg, env, lenv)), lenv);
		}
		else
			*arg += ((dest[i++] = **arg), 1);
	}
	return (i);
}

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

	i = -1;
	while (cmd->args[++i])
	{
		if (get_status() == 13)
			set_status(0);
		new_len = ft_getlen_args(cmd->args[i], env);
		if (new_len != (int)ft_strlen(cmd->args[i]))
		{
			tmp = cmd->args[i];
			cmd->args[i] = (char *)malloc(sizeof(char) * (new_len + 1));
			if (!cmd->args[i])
				return (NULL);
			ft_bzero(cmd->args[i], new_len + 1);
			(ft_addnew_args(cmd->args[i], tmp, env), free(tmp));
		}
	}
	cmd->args = ft_filter_args(cmd->args);
	return (cmd);
}
