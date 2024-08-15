/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:39:28 by hramaros          #+#    #+#             */
/*   Updated: 2024/08/15 11:22:48 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

t_hist_elem	*new_history(char *command, int position)
{
	t_hist_elem	*result;

	if (!command)
		return (printf("The command to parse in history is null.\n"), NULL);
	result = malloc(sizeof(t_hist_elem));
	if (!result)
		return (printf("Failed to malloc the command history."), NULL);
	result->command = ft_strdup(command);
	result->line_number = position;
	result->is_offset_to_write = 0;
	result->next = NULL;
	return (result);
}

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

// TOTEST servira a ecrire l'historique en memoire vers le fichier d'historique
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
	close(fd);
	// etape 2: ecrire a partir de cet offset (a risque d'ecraser le contenu)
	fd = open(history_path, O_RDWR);
	if (fd < 0)
		return (printf("Failed to write the history\n"), 0);
	go_to_offset(fd, ft_get_history_offsetted(hist_elem));
	write_cmd_typed_after_offset(fd, ft_get_history_offsetted(hist_elem)->next);
	// etape 3: ecrire le remains vers la fin
	write(fd, remains, ft_strlen(remains));
	return (close(fd), 1);
}

// va servir a modifier l'historique en memoire actuelle
void	modify_curr_history(void)
{
	printf("Modifie l'historique en memoire...\n");
	return ;
}
