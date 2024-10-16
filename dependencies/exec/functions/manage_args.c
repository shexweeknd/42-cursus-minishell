/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:14:57 by hramaros          #+#    #+#             */
/*   Updated: 2024/10/16 13:51:12 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

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
				i += ((*arg += 1), ft_add_status(dest + i));
			else if (!ft_isalpha(**arg) && **arg != '_')
				i += ((dest[i] = '$'), lenv);
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

void	ft_manage_arg(char **arg, t_env *env)
{
	int		new_len;
	char	*tmp;

	new_len = ft_getlen_args(*arg, env);
	if (ft_strchr(*arg, '$') || \
		new_len != (int)ft_strlen(*arg))
	{
		*arg = ((tmp = *arg), NULL);
		*arg = (char *)malloc(sizeof(char) * (new_len + 1));
		if (!*arg)
			return ;
		ft_bzero(*arg, new_len + 1);
		ft_addnew_args(*arg, tmp, env);
		free (tmp);
	}
}

void	*ft_manage_args(t_cmd *cmd, t_env *env)
{
	int		i;
	t_rfile	*tmp;

	i = -1;
	while (cmd->args[++i])
	{
		if (get_status() == 13)
			set_status(0);
		ft_manage_arg(&cmd->args[i], env);
	}
	tmp = cmd->file_in;
	while (tmp)
		tmp = ((ft_manage_arg(&tmp->args, env)), tmp->next);
	tmp = cmd->file_out;
	while (tmp)
		tmp = ((ft_manage_arg(&tmp->args, env)), tmp->next);
	return (cmd);
}
