# PROGRAM NAME
NAME		= libexec.a

# FILES
FILES		= ft_exec.c
SRC_FILES	= \
				echo.c		\
				ft_env.c	\
				export.c	\
				pwd.c		\
				unset.c		\
				cd.c		\
				ft_exit.c

FUNC_FILES	= \
				exec_utils.c			\
				ft_edit_variable.c		\
				manage_args.c			\
				manage_args_utils.c		\
				ft_file_descriptor.c	\
				exec_checker.c			\
				exec_checker_utils.c	\
				exec_process.c			\
				ft_file_checker.c

# SRC FILES
FUNC		= $(FUNC_FILES:%.c=functions/%.c)
SRC			= $(SRC_FILES:%.c=src/%.c)

# OBJECT FILES
OBJS		= $(FILES:%.c=output/%.o)
SRC_OBJS	= $(SRC:src/%.c=output/%.o)
FUNC_OBJS	= $(FUNC:functions/%.c=output/%.o)

# DEPENDENCIES
DEP_PATH	= ..
LIBFT_PATH	= $(DEP_PATH)/libft
STATIC_PATH	= $(DEP_PATH)/static
ENV_PATH	= $(DEP_PATH)/env
CMD_PATH	= $(DEP_PATH)/cmd
HIST_PATH	= $(DEP_PATH)/history
SIG_PATH	= $(DEP_PATH)/sig
HD_PATH		= $(DEP_PATH)/heredoc
ERR_PATH	= $(DEP_PATH)/err

# INCLUDES
EXEC_INC	= -Iincludes
TEMPLATES	= -I$(DEP_PATH)/templates
LIBFT_INC	= -I$(LIBFT_PATH)/includes
STATIC_INC	= -I$(STATIC_PATH)/includes
ENV_INC		= -I$(ENV_PATH)/includes
CMD_INC		= -I$(CMD_PATH)/includes
HIST_INC	= -I$(HIST_PATH)/includes
SIG_INC		= -I$(SIG_PATH)/includes
HD_INC		= -I$(HD_PATH)/includes
ERR_INC		= -I$(ERR_PATH)/includes
INCLUDES	= \
				$(LIBFT_INC)	\
				$(TEMPLATES)	\
				$(STATIC_INC)	\
				$(ENV_INC)		\
				$(HIST_INC)		\
				$(HD_INC)		\
				$(ERR_INC)		\
				$(SIG_INC)		\
				$(CMD_INC)		\
				$(EXEC_INC)

# COMPILATION CONFIG
CC			= cc -g
AR			= ar rcs
CFLAGS		= -Wall -Wextra -Werror

# FUNCTION
define Compile
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
endef

define CreateLib
	$(AR) $(2) $(1)
endef

# COMMANDS
all			: $(NAME)

output		:
				@if [ ! -d output ]; then mkdir output; fi

output/%.o	: %.c | output
				$(call Compile,$<,$@)

output/%.o	: functions/%.c | output
				$(call Compile,$<,$@)

output/%.o	: src/%.c | output
				$(call Compile,$<,$@)

$(NAME)		: $(OBJS) $(SRC_OBJS) $(FUNC_OBJS)
				$(call CreateLib,$^,$@)

clean		:
				$(call Makelibs, clean)
				rm -rf $(OBJS)
				rm -rf $(FUNC_OBJS)
				rm -rf $(SRC_OBJS)

fclean		: clean
				$(call Makelibs, fclean)
				rm -rf $(NAME)

re			: fclean all

.PHONY		: clean fclean re all