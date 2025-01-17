# PROGRAM NAME
NAME			= minishell

# FILES
FILES			= main.c

# OBJECT FILES
OBJS			= $(FILES:%.c=output/%.o)

# DEPENDENCIES
DEP_PATH		= ./dependencies
LIBFT_PATH		= $(DEP_PATH)/libft
ENV_PATH		= $(DEP_PATH)/env
CMD_PATH		= $(DEP_PATH)/cmd
HISTORY_PATH	= $(DEP_PATH)/history
PROMPT_PATH		= $(DEP_PATH)/prompt
ERR_PATH		= $(DEP_PATH)/err
EXEC_PATH		= $(DEP_PATH)/exec
SIG_PATH		= $(DEP_PATH)/sig
STATIC_PATH		= $(DEP_PATH)/static
HEREDOC_PATH		= $(DEP_PATH)/heredoc

# LIBS
LIBFT_LIB		= -L$(LIBFT_PATH) -lft
ENV_LIB			= -L$(ENV_PATH) -lenv
CMD_LIB			= -L$(CMD_PATH) -lcmd
HISTORY_LIB 	= -L$(HISTORY_PATH) -lhistory
PROMPT_LIB 		= -L$(PROMPT_PATH) -lprompt
ERR_LIB 		= -L$(ERR_PATH) -lerr
EXEC_LIB 		= -L$(EXEC_PATH) -lexec
SIG_LIB 		= -L$(SIG_PATH) -lsig
STATIC_LIB 		= -L$(STATIC_PATH) -lstatic
HEREDOC_LIB 	= -L$(HEREDOC_PATH) -lhd
LIBS			= \
					$(EXEC_LIB)		\
					$(CMD_LIB)		\
					$(PROMPT_LIB)	\
					$(ERR_LIB)		\
					$(HEREDOC_LIB)	\
					$(HISTORY_LIB)	\
					$(SIG_LIB)		\
					$(ENV_LIB)		\
					$(STATIC_LIB)	\
					$(LIBFT_LIB)	\
					-lreadline -Wno-unused-command-line-argument

# INCLUDES
MINISH_INC		= -Iincludes
TEMPLATES		= -I$(DEP_PATH)/templates
LIBFT_INC		= -I$(LIBFT_PATH)/includes
ENV_INC			= -I$(ENV_PATH)/includes
CMD_INC			= -I$(CMD_PATH)/includes
HISTORY_INC 	= -I$(HISTORY_PATH)/includes
PROMPT_INC 		= -I$(PROMPT_PATH)/includes
ERR_INC 		= -I$(ERR_PATH)/includes
EXEC_INC		= -I$(EXEC_PATH)/includes
SIG_INC			= -I$(SIG_PATH)/includes
STATIC_INC		= -I$(STATIC_PATH)/includes
HEREDOC_INC		= -I$(HEREDOC_PATH)/includes
INCLUDES		= \
					$(LIBFT_INC)	\
					$(TEMPLATES)	\
					$(SIG_INC)		\
					$(ENV_INC)		\
					$(ERR_INC)		\
					$(HEREDOC_INC)	\
					$(HISTORY_INC)	\
					$(STATIC_INC)	\
					$(PROMPT_INC)	\
					$(CMD_INC)		\
					$(EXEC_INC)		\
					$(MINISH_INC)

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
	make $(1) -C $(SIG_PATH)
	make $(1) -C $(STATIC_PATH)
	make $(1) -C $(HISTORY_PATH)
	make $(1) -C $(HEREDOC_PATH)
	make $(1) -C $(ERR_PATH)
	make $(1) -C $(PROMPT_PATH)
	make $(1) -C $(CMD_PATH)
	make $(1) -C $(EXEC_PATH)
endef

define CreateExe
	$(call MakeLibs,all)
	$(CC) $(CFLAGS) $(1) -o $(2) $(LIBS)
endef

# COMMANDS
## Compilation
all			: $(NAME)

%			:
				make all -C $(DEP_PATH)/$@

output		:
				@if [ ! -d output ]; then mkdir output; fi

output/%.o	: %.c | output
				$(call Compile,$<,$@)

$(NAME)		: $(OBJS)
				$(call CreateExe,$^,$@)

## Clean
clean		:
				$(call MakeLibs,clean)
				rm -rf $(OBJS)

fclean		: clean
				$(call MakeLibs,fclean)
				rm -rf $(NAME)

re			: fclean all

.PHONY		: clean fclean re all