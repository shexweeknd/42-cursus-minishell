# PROGRAM NAME
NAME		= libhistory.a

# FILES
FILES		= history.c
FUNC_FILES	= history_utils.c \
			history_getters.c \
			history_setters.c \
			history_debug.c

# SRC FILES
FUNC		= $(FUNC_FILES:%.c=functions/%.c)

# OBJECT FILES
OBJS		= $(FILES:%.c=output/%.o)
FUNC_OBJS	= $(FUNC:functions/%.c=output/%.o)

# DEPENDENCIES
DEP_PATH	= ..
LIBFT_PATH	= $(DEP_PATH)/libft

# INCLUDES
HISTORY_INC	= -Iincludes
TEMPLATES	= -I$(DEP_PATH)/templates
LIBFT_INC	= -I$(LIBFT_PATH)/includes
INCLUDES	= $(LIBFT_INC) $(TEMPLATES) $(HISTORY_INC)

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

src			:
				@if [ ! -d src ]; then mkdir src; fi

output		:
				@if [ ! -d output ]; then mkdir output; fi

output/%.o	: %.c | output
				$(call Compile,$<,$@)

output/%.o	: */%.c | output
				$(call Compile,$<,$@)

$(NAME)		: $(OBJS) $(FUNC_OBJS) | src
				$(call CreateLib,$^,$@)

clean		:
				rm -rf $(OBJS)
				rm -rf $(FUNC_OBJS)

fclean		: clean
				rm -rf $(NAME)

re			: fclean all

.PHONY		: clean fclean re all