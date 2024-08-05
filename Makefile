# PROGRAM NAME
NAME		= minishell

# FILES
FILES		= main.c
FUNC_FILES	= ""
SRC_FILES	= ""

# SRC FILES
FUNC		= $(FUNC_FILES:%.c=functions/%.c)
SRC			= $(SRC_FILES:%.c=src/%.c)

# OBJECT FILES
OBJS		= $(FILES:%.c=output/%.o)
FUNC_OBJS	= $(FUNC:functions/%.c=output/%.o)
SRC_OBJS	= $(SRC:src/%.c=output/%.o)

# DEPENDENCIES
DEP_PATH	= ./dependencies
LIBFT_PATH	= $(DEP_PATH)/libft
ENV_PATH	= $(DEP_PATH)/env

# LIBS
LIBFT_LIB	= -L$(LIBFT_PATH) -lft
ENV_LIB		= -L$(ENV_PATH) -lenv
LIBS		= $(ENV_LIB) $(LIBFT_LIB)

# INCLUDES
MINISH_INC	= -Iincludes
LIBFT_INC	= -I$(LIBFT_PATH)
ENV_INC		= -I$(ENV_PATH)/includes
INCLUDES	= $(MINISH_INC) $(LIBFT_INC) $(ENV_INC)

# COMPILATION CONFIG
CC		= cc -g
CFLAGS	= -Wall -Wextra -Werror

# FUNCTION
define Compile
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
endef

define CompileLibs
	make -C $(LIBFT_PATH)
	make -C $(ENV_PATH)
endef

define CreateExe
	$(call CompileLibs)
	$(CC) $(CFLAGS) $(1) -o $(2) $(LIBS)
endef

# COMMANDS
## Compilation
all			: $(NAME)

output		:
				@if [ ! -d output ]; then mkdir output; fi

output/%.o	: %.c | output
				$(call Compile,$<,$@)

output/%.o	: */%.c | output
				$(call Compile,$<,$@)

$(NAME)		: $(OBJS)

				$(call CreateExe,$^,$@)

## Test
run			: all
				./$(NAME)

test		: all
				valgrind --leak-check=full -s ./$(NAME)

## Clean
clean		:
				make clean -C $(LIBFT_PATH)
				make clean -C $(ENV_PATH)
				rm -rf $(OBJS)

fclean		: clean
				make fclean -C $(LIBFT_PATH)
				make fclean -C $(ENV_PATH)
				rm -rf $(NAME)

re			: fclean all

.PHONY		: clean fclean re all