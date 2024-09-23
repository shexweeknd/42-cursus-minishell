/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:57:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/23 16:20:46 by hramaros         ###   ########.fr       */
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

int	hd_valid_before(char *line)
{
	(void)line;
	return (1);
}

// sert a skipper jusqu'a occurence de "<<"
int	skip_until_hd(char *line)
{
	(void)line;
	return (1);
}

// verifie si la syntaxe de hd est conforme au: [<<] [non_op_token]
int	is_valid_hd(char *prompt)
{
	(void)prompt;
	return (1);
}

// sert a skipper la syntaxe [<<] [eof]
int	skip_hd_eof(char *line)
{
	(void)line;
	return (1);
}

// TODO: mettre dans une boucle
int	hd_check_syntax_err(char *prompt)
{
	t_eofs	*eofs;

	eofs = NULL;
	// check les commandes before le heredoc
	if (!hd_valid_before(prompt))
		return (process_hd(eofs), 1);
	prompt += skip_until_hd(prompt);
	// check le heredoc en question: [<<] [non_op_token]
	if (!is_valid_hd(prompt))
		return (process_hd(eofs), 1);
	//- si tout est correct devant le hd alors on ajoute les eof a la liste des eof (liste de char*)
	eofs = append_eofs(eofs, get_eof(prompt));
	if (!eofs)
		return (process_hd(eofs), 1);
	// - on passe au check du char apres le non_op_token
	prompt += skip_hd_eof(prompt);
	// on process les fd grace a la liste des eofs char *
	return (process_hd(eofs), 0);
}

int	check_syntax_err(char *prompt)
{
	int	flag;

	flag = 0;
	if (is_only_spaces(prompt))
		flag = 1;
	if (_hd_occ(prompt))
		flag = hd_check_syntax_err(prompt);
	else if (!flag && is_unexpected(prompt, 0))
		flag = 1;
	if (!flag && is_unexpected(prompt, 1))
		flag = 1;
	return (flag);
}
