#ifndef HISTORY_H
# define HISTORY_H

#include <stdio.h>
#include "libft.h"

typedef struct s_hist_elem
{
    int pos;
    char *content;
    struct s_hist_elem *next;
}   t_hist_elem;

void	set_history(void);

void	get_history(void);

#endif