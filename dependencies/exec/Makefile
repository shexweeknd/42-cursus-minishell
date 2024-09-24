# PROGRAM NAME
NAME		= libexec.a

# FILES
FILES		= ft_exec.c #exec_utils.c
SRC_FILES	= \
				echo.c		\
				ft_env.c	\
				export.c	\
				pwd.c		\
				unset.c		\
				cd.c		\
				ft_exit.c

FUNC_FILES	= \
				rootpath.c				\
				exec_utils.c		\
				manage_args.c		\
				manage_args_utils.c	\
				ft_status.c			\
				ft_file_descriptor.c

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
ENV_PATH	= $(DEP_PATH)/env
CMD_PATH	= $(DEP_PATH)/cmd
HISTORY_PATH= $(DEP_PATH)/history

# LIBS
LIBFT		= -L$(LIBFT_PATH) -lft
ENV			= -L$(ENV_PATH) -lenv
CMD			= -L$(CMD_PATH) -lcmd
HISTORY		= -L$(HISTORY_PATH) -lhistory
LIBS		= $(HISTORY) $(CMD) $(ENV) $(LIBFT) -Wno-unused-command-line-argument

# INCLUDES
LIBFT_INC	= -I$(LIBFT_PATH)/includes
ENV_INC		= -I$(ENV_PATH)/includes
CMD_INC		= -I$(CMD_PATH)/includes
HISTORY_INC	= -I$(HISTORY_PATH)/includes
EXEC_INC	= -Iincludes
INCLUDES	= $(LIBFT_INC) $(ENV_INC) $(CMD_INC) $(EXEC_INC) $(HISTORY_INC)

# COMPILATION CONFIG
CC		= cc -g
AR		= ar rcs
CFLAGS	= -Wall -Wextra -Werror

# FUNCTION
define Compile
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2) $(LIBS)
endef

define MakeLibs
	make $(1) -C $(LIBFT_PATH)
	make $(1) -C $(ENV_PATH)
	make $(1) -C $(CMD_PATH)
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
				$(call Makelibs)
				$(call CreateLib,$^,$@)

clean		:
				$(call Makelibs, clean)
				rm -rf $(OBJS)
				rm -rf $(FUNC_OBJS)

fclean		: clean
				$(call Makelibs, fclean)
				rm -rf $(NAME)

re			: fclean all

.PHONY		: clean fclean re all