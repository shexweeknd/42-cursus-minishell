/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:39:28 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/14 12:10:02 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

// servira a parser l'historique contenu dans le fichier historique
t_hist_elem	*get_history(char *history_path)
{
	t_hist_elem	*result;
	int			fd;
	size_t		index;
	size_t		size;

	fd = open(history_path, O_RDONLY);
	if (fd < 0)
		return (0);
	result = NULL;
	size = count_files_line(history_path);
	index = 0;
	while (index < (size + 1))
	{
		result = ft_append_hist_elem(result, get_next_line(fd));
		index++;
	}
	return (close(fd), result);
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
