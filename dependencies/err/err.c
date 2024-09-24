/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:57:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/24 09:59:15 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_err.h"

int	check_syntax_err_(char *prompt)
{
	int	flag;

	flag = 0;
	if (is_only_spaces(prompt))
		flag = 1;
	else if (!flag && is_unexpected(prompt, 0))
		flag = 1;
	if (_hd_occ(prompt))
		printf("processing hd...\n");
	if (!flag && is_unexpected(prompt, 1))
		flag = 1;
	return (flag);
}

// TOTEST
// check les unexpected commme unexpected_err (verifie seulement les erreurs lvl 0)
// s'arrette seulement lorsqu'il voit un '<<'
int	hd_valid_before(char *line)
{
	int	flag;
	int	lvl;

	lvl = 0;
	flag = 0;
	if (!check_op_at_start(line))
		return (1);
	while (*line && !flag && ft_strncmp(line, "<<", 2))
	{
		if (!ft_strncmp(line, ">>", 2))
			line += chev_check(line, &flag, 2, lvl);
		if (!ft_strncmp(line, "<<", 2))
			break ;
		else if ((*line == '>' || *line == '<') && !flag)
			line += chev_check(line, &flag, 1, lvl);
		else if ((!ft_strncmp(line, "||", 2) || !ft_strncmp(line, "&&", 2))
			&& !flag)
			line += op_check(line, &flag, 2, lvl);
		else if ((*line == '|' || *line == '&') && !flag)
			line += op_check(line, &flag, 1, lvl);
		else
			line++;
	}
	return (!flag);
}

// TOTEST
// sert a skipper jusqu'a occurence de "<<"
int	skip_until_hd(char *line)
{
	int	result;

	result = 0;
	while (line[result] && ft_strncmp(&line[result], "<<", 2))
		result++;
	return (result);
}

// verifie si la syntaxe de hd est conforme au: [<<] [non_op_token]
int	is_valid_hd(char *line)
{
	int	flag;
	int	lvl;

	lvl = 0;
	flag = 0;
	if (!ft_strncmp(line, "<<", 2))
		chev_check(line, &flag, 2, lvl);
	return (!flag);
}

// TOTEST
// sert a skipper la syntaxe [<<] [eof]
int	skip_hd_eof(char *line)
{
	int	result;

	result = 0;
	if (!ft_strncmp(line, "<<", 2))
		result += 2;
	while (ft_isspace(line[result]))
		result++;
	while (!ft_isspace(line[result]))
	{
		if (ft_is_delimiter(line[result]) || ft_is_redirect(line[result]))
			break ;
		result++;
	}
	return (result);
}

// TODO: mettre dans une boucle
int	hd_check_syntax_err(char *prompt)
{
	t_eofs	*eofs;

	eofs = NULL;
	while (*prompt)
	{
		// check les commandes before le heredoc
		if (!hd_valid_before(prompt))
			return (process_hd(eofs), free_eofs(eofs), 1);
		prompt += skip_until_hd(prompt);
		// check le heredoc en question: [<<] [non_op_token]
		if (!is_valid_hd(prompt))
			return (process_hd(eofs), free_eofs(eofs), 1);
		//- si tout est correct devant le hd alors on ajoute les eof a la liste des eof (liste de char*)
		eofs = append_eofs(eofs, get_eof(prompt));
		if (!eofs)
			return (process_hd(eofs), free_eofs(eofs), 1);
		// - on passe au check du char apres le non_op_token
		prompt += skip_hd_eof(prompt);
	}
	// on process les fd grace a la liste des eofs char *
	return (process_hd(eofs), free_eofs(eofs), 0);
}

int	check_syntax_err(char *prompt)
{
	int	flag;

	flag = 0;
	if (is_only_spaces(prompt))
		flag = 1;
	if (_hd_occ(prompt))
	{
		flag = hd_check_syntax_err(prompt);
		prompt += skip_until_hd(prompt);
		prompt += skip_hd_eof(prompt);
	}
	else if (!flag && is_unexpected(prompt, 0))
		flag = 1;
	if (!flag && is_unexpected(prompt, 1))
		flag = 1;
	return (flag);
}
