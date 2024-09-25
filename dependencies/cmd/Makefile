# PROGRAM NAME
NAME		= libcmd.a

# FILES
FILES		= cmd.c cmd_utils.c
FUNC_FILES	= \
				cmd_extra.c			\
				cmd_extra_utils.c	\
				cmd_show.c			\
				cmd_free.c

# SRC FILES
FUNC		= $(FUNC_FILES:%.c=functions/%.c)

# OBJECT FILES
OBJS		= $(FILES:%.c=output/%.o)
FUNC_OBJS	= $(FUNC:functions/%.c=output/%.o)

# DEPENDENCIES
DEP_PATH	= ..
LIBFT_PATH	= $(DEP_PATH)/libft
STATUS_PATH	= $(DEP_PATH)/status
SIG_PATH	= $(DEP_PATH)/sig
ERR_PATH	= $(DEP_PATH)/err
HD_PATH		= $(DEP_PATH)/heredoc

# INCLUDES
CMD_INC		= -Iincludes
TEMPLATES	= -I$(DEP_PATH)/templates
LIBFT_INC	= -I$(LIBFT_PATH)/includes
STATUS_INC	= -I$(STATUS_PATH)/includes
SIG_INC		= -I$(SIG_PATH)/includes
HD_INC		= -I$(HD_PATH)/includes
ERR_INC		= -I$(ERR_PATH)/includes
INCLUDES	= \
				$(TEMPLATES)	\
				$(LIBFT_INC)	\
				$(STATUS_INC)	\
				$(SIG_INC)		\
				$(ERR_INC)		\
				$(HD_INC)		\
				$(CMD_INC)

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