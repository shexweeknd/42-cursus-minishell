/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:39:28 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/14 19:04:15 by ballain          ###   ########.fr       */
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
		result = ft_append_hist_elem(result, get_next_line(fd), index + 1);
		index++;
	}
	ft_get_last_history(result)->is_offset_to_write = 1;
	return (close(fd), result);
}

// servira a ecrire l'historique en memoire vers le fichier d'historique
int	set_history(t_hist_elem *hist_elem, char *history_path)
{
	int		fd;
	char	*remains;

	fd = open(history_path, O_RDWR);
	if (fd < 0)
		return (printf("Failed to write the history\n"), 0);
	// etape 0: voir l'offset correspondant a is_offset puis positionner le cursor
	go_to_offset(fd, ft_get_history_offsetted(hist_elem));
	// etape 1: prendre le remains dans un get_next_line
	remains = get_things_after_offset(fd);
	// etape 2: ecrire a partir de cet offset (a risque d'ecraser le contenu)
	fd = open(history_path, O_RDWR);
	if (fd < 0)
		return (printf("Failed to write the history\n"), 0);
	go_to_offset(fd, ft_get_history_offsetted(hist_elem));
	// write_content_typed_after_offset();
	// etape 3: ecrire le remains vers la fin
	write(fd, remains, ft_strlen(remains));
	return (1);
}

// va servir a modifier l'historique en memoire actuelle
void	modify_curr_history(void)
{
	printf("Modifie l'historique en memoire...\n");
	return ;
}
