#ifndef HIST_STRUCT_H
# define HIST_STRUCT_H

enum					e_hist_err_status
{
	ERROR_READ_STATUS,
	ERROR_WRITE_STATUS,
	SUCCESS_READ_STATUS,
	SUCCESS_WRITE_STATUS
};

typedef struct s_hist_elem
{
	int					is_offset;
	int					line_nbr;
	char				*command;
	struct s_hist_elem	*next;
}						t_hist_elem;

#endif
