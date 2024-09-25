# PROGRAM NAME
NAME		= libprompt.a

# FILES
FILES		= \
				prompt.c			\
				prompt_utils.c 		\

FUNC_FILES	= \
				prompt_checker.c 	\
				prompt_debug.c 		\
				open_stdin.c

# SRC FILES
FUNC		= $(FUNC_FILES:%.c=functions/%.c)

# OBJECT FILES
OBJS		= $(FILES:%.c=output/%.o)
FUNC_OBJS	= $(FUNC:functions/%.c=output/%.o)

# DEPENDENCIES
DEP_PATH	= ..
LIBFT_PATH	= $(DEP_PATH)/libft
ENV_PATH	= $(DEP_PATH)/env
ERR_PATH	= $(DEP_PATH)/err
HD_PATH		= $(DEP_PATH)/heredoc
HIST_PATH	= $(DEP_PATH)/history
SIG_PATH	= $(DEP_PATH)/sig
STATUS_PATH	= $(DEP_PATH)/status

# INCLUDES
PROMPT_INC	= -Iincludes
TEMPLATES	= -I$(DEP_PATH)/templates
LIBFT_INC	= -I$(LIBFT_PATH)/includes
ENV_INC		= -I$(ENV_PATH)/includes
HIST_INC 	= -I$(HIST_PATH)/includes
ERR_INC 	= -I$(ERR_PATH)/includes
SIG_INC		= -I$(SIG_PATH)/includes
STATUS_INC	= -I$(STATUS_PATH)/includes
HD_INC		= -I$(HD_PATH)/includes
INCLUDES	= \
				$(TEMPLATES)	\
				$(LIBFT_INC)	\
				$(SIG_INC)		\
				$(ENV_INC)		\
				$(HIST_INC)		\
				$(ERR_INC)		\
				$(STATUS_INC)	\
				$(HD_INC)		\
				$(PROMPT_INC)

# COMPILATION CONFIG
CC		= cc -g
AR		= ar rcs
CFLAGS	= -Wall -Wextra -Werror

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

output/%.o	: */%.c | output
				$(call Compile,$<,$@)

$(NAME)		: $(OBJS) $(FUNC_OBJS)
				make -C $(LIBFT_PATH)
				$(call CreateLib,$^,$@)

clean		:
				rm -rf $(OBJS)
				rm -rf $(FUNC_OBJS)

fclean		: clean
				rm -rf $(NAME)

re			: fclean all

.PHONY		: clean fclean re all