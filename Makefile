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

# INCLUDES
MINISH_INC	= -Iincludes

# COMPILATION CONFIG
CC		= cc -g
CFLAGS	= -Wall -Wextra -Werror $(MINISH_INC) -Lreadline

# FUNCTION
define Compile
	$(CC) $(CFLAGS) -c $(1) -o $(2)
endef

define CreateExe
	$(CC) $(CFLAGS) $(1) -o $(2)
endef

# COMMANDS
all			: $(NAME)

output		:
				@if [ ! -d output ]; then mkdir output; fi

output/%.o	: %.c | output
				$(call Compile,$<,$@)

output/%.o	: */%.c | output
				$(call Compile,$<,$@)

$(NAME)		: $(OBJS)
				$(call CreateExe,$<,$@)

run			:
				@./$(NAME)

clean		:
				rm -rf $(OBJS)

fclean		: clean
				rm -rf $(NAME)

re			: fclean all

.PHONY		: clean fclean re all