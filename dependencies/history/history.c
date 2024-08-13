/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:39:28 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/13 12:55:39 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

// TOTEST si fonctionne
static t_hist_elem	*parse_to_hist_elem(char **content)
{
	t_hist_elem	*result;
	t_hist_elem	*temp;

	result = malloc(sizeof(t_hist_elem));
	if (!result)
		return (NULL);
	temp = result;
	while (content)
	{
		temp->command = *content;
		content++;
		if (!content)
			temp->next = NULL;
		else
		{
			temp->next = malloc(sizeof(t_hist_elem));
			if (!temp->next)
				return (free_history(result), NULL);
		}
		temp = temp->next;
	}
	return (result);
}

// servira a parser l'historique contenu dans le fichier historique
t_hist_elem	*get_history(char *history_path)
{
	t_hist_elem	*result;
	char		**content;

	content = parse_twodim(history_path);
	if (!content)
		return (NULL);
	result = parse_to_hist_elem(content);
	if (!result)
		return (free(content), NULL);
	return (free(content), result);
}

// servira a ecrire l'historique en memoire vers le fichier d'historique
void	set_history(char *history_path)
{
	printf("En train d'ecrire le contenu dans %s...\n", history_path);
	return ;
}

// va servir a modifier l'historique en memoire actuelle
void	modify_curr_history(void)
{
	printf("Modifie l'historique en memoire...\n");
	return ;
}
