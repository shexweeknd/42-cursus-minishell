#ifndef CMD_H
# define CMD_H

# include <stdio.h>
# include <stdlib.h>
# include "cmd_struct.h"
# include "libft.h"

int		ft_is_cmd_sep(const int c);
void	ft_add_cmd_info(t_cmd *cmd, void *value, int type);

#endif