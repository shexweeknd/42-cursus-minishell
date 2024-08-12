# include "cmd.h"

// void	_free(void *value, t_list_type type)
// {
// 	if (!value)
// 		return ;
// 	if (type == CMD)
// 	{
// 		ft_show_cmd((t_cmd *)value);
// 		if (((t_cmd *)value)->name)
// 			free(((t_cmd *)value)->name);
// 		if (((t_cmd *)value)->option)
// 			free(((t_cmd *)value)->option);
// 		if (((t_cmd *)value)->arg)
// 			free(((t_cmd *)value)->arg);
// 		if (((t_cmd *)value)->io_arg)
// 		{
// 			_loop((void **)&((t_cmd *)value)->io_arg, _free, IO_ARG);
// 		}
// 		free(value);
// 	}
// 	else if (type == IO_ARG && value)
// 	{
// 		_free((void *)((t_io_arg *)value)->arg, IO_ARG);
// 		free(value);
// 	}
// 		// _loop((void **)&((t_cmd *)value)->io_arg, _free, IO_ARG);

// 	// if (value)
// }

// void	ft_free_cmds(t_cmd *cmd)
// {
// 	printf("_______ FREE BEGIN _______\n");
// 	_loop((void **)&cmd, _free, CMD);
// 	printf("_______ FREE END   _______\n"); 
// }