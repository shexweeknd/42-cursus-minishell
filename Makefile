# PROGRAM NAME
NAME			= minishell

# FILES
FILES			= main.c
FUNC_FILES		= ""
SRC_FILES		= ""

# SRC FILES
FUNC			= $(FUNC_FILES:%.c=functions/%.c)
SRC				= $(SRC_FILES:%.c=src/%.c)

# OBJECT FILES
OBJS			= $(FILES:%.c=output/%.o)
FUNC_OBJS		= $(FUNC:functions/%.c=output/%.o)
SRC_OBJS		= $(SRC:src/%.c=output/%.o)

# DEPENDENCIES
DEP_PATH		= ./dependencies
LIBFT_PATH		= $(DEP_PATH)/libft
ENV_PATH		= $(DEP_PATH)/env
CMD_PATH		= $(DEP_PATH)/cmd
HISTORY_PATH	= $(DEP_PATH)/history
PROMPT_PATH		= $(DEP_PATH)/prompt
ERR_PATH		= $(DEP_PATH)/err
EXEC_PATH		= $(DEP_PATH)/exec

# LIBS
LIBFT_LIB		= -L$(LIBFT_PATH) -lft
ENV_LIB			= -L$(ENV_PATH) -lenv
CMD_LIB			= -L$(CMD_PATH) -lcmd
HISTORY_LIB 	= -L$(HISTORY_PATH) -lhistory
PROMPT_LIB 		= -L$(PROMPT_PATH) -lprompt
ERR_LIB 		= -L$(ERR_PATH) -lerr
EXEC_LIB 		= -L$(EXEC_PATH) -lexec
LIBS			= $(EXEC_LIB) $(HISTORY_LIB) $(PROMPT_LIB) $(ERR_LIB) $(CMD_LIB) $(ENV_LIB) $(LIBFT_LIB) -lreadline -Wno-unused-command-line-argument

# INCLUDES
MINISH_INC		= -Iincludes
LIBFT_INC		= -I$(LIBFT_PATH)/includes
ENV_INC			= -I$(ENV_PATH)/includes
CMD_INC			= -I$(CMD_PATH)/includes
HISTORY_INC 	= -I$(HISTORY_PATH)/includes
PROMPT_INC 		= -I$(PROMPT_PATH)/includes
ERR_INC 		= -I$(ERR_PATH)/includes
EXEC_INC		= -I$(EXEC_PATH)/includes
INCLUDES		= $(MINISH_INC) $(LIBFT_INC) $(ENV_INC) $(CMD_INC) $(HISTORY_INC) $(PROMPT_INC) $(ERR_INC) $(SAVE_INC) $(EXEC_INC)

# COMPILATION CONFIG
CC				= cc -g
CFLAGS			= -Wall -Wextra -Werror

# FUNCTION
define Compile
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
endef

define MakeLibs
	make $(1) -C $(LIBFT_PATH)
	make $(1) -C $(ENV_PATH)
	make $(1) -C $(CMD_PATH)
	make $(1) -C $(HISTORY_PATH)
	make $(1) -C $(PROMPT_PATH)
	make $(1) -C $(ERR_PATH)
	make $(1) -C $(EXEC_PATH)
endef

define CreateExe
	$(call MakeLibs)
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

test\:%		: all
				valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME) $(subst test:,,$@)

## Save
push\:%		: fclean
				git status
				git add *
				git status
				git commit -m $(subst push:,,$@)
				git push

## Clean
clean		:
				$(call MakeLibs, clean)
				rm -rf $(OBJS)

fclean		: clean
				$(call MakeLibs, fclean)
				rm -rf $(NAME)

re			: fclean all

.PHONY		: clean fclean re all \
				leaks suppr