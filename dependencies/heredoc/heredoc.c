/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:52:30 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/20 11:08:18 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

void	fullfill_fd(int fd, char *eof)
{
	(void)fd;
	(void)eof;
	// cette fonction servira a remplir le fd a partir du contenu de readline
}

void	init_hd(t_hd *hd, char *eof)
{
	if (hd)
		return ;
	hd = (t_hd *)malloc(sizeof(hd));
	if (!hd)
		return ;
	pipe(hd->fd);
	hd->pos = 0;
	fullfill_fd(hd->fd[0], eof);
	hd->next = NULL;
}

void	add_hd(t_hd *hd, char *eof)
{
	int	pos;

	pos = 0;
	while (hd->next)
	{
		hd = hd->next;
		pos++;
	}
	hd->next = (t_hd *)malloc(sizeof(hd));
	if (!hd->next)
		return ;
	hd = hd->next;
	pipe(hd->fd);
	hd->pos = pos + 1;
	fullfill_fd(hd->fd[0], eof);
	hd->next = NULL;
}

t_hd	*hd_cmd(char cmd, char *eof)
{
	static t_hd	*hd = NULL;

	if (cmd == 'g')
		return (hd);
	if (cmd == 'i')
		return (init_hd(hd, eof), hd);
	if (cmd == 'a')
		return (add_hd(hd, eof), hd);
	if (cmd == 'f')
		return (printf("freeing the static hd_store\n"), NULL);
	return (NULL);
}

// ne doit prendre que le premier eof a cote du operateur du hd
static char	*get_eof(char *line)
{
	(void)line;
	// servira a prendre le eof dans la ligne
	return (NULL);
}

static void	recurse_free(t_hd *hd)
{
	if (!hd)
	{
		free(hd);
		return ;
	}
	recurse_free(hd->next);
	free(hd);
	return ;
}

void	free_hd(void)
{
	t_hd	*hd;

	hd = hd_cmd('g', NULL);
	if (!hd)
	{
		free(hd);
		return ;
	}
	recurse_free(hd);
}

// TODO process_hd: mettre en recursive dans le cas ou on a plusieurs operateurs hd dans une seule ligne
void	process_hd(char *line)
{
	t_hd	*hd;
	char	*eof;

	eof = get_eof(line);
	hd = hd_cmd('g', NULL);
	if (!hd)
		hd = hd_cmd('i', eof);
	// etape 1: ouvrir un pipe et le mettre a la fin du tableau
	hd = hd_cmd('a', eof);
	// etape 2: readline avec ps2 tant qu'on a pas le eof
	// etape 3: remplir le pipe a la fin du tableau de fd
	// etape finale : skip le hd courant puis mettre en recursive s'il y a encore un hd dans la ligne
}
