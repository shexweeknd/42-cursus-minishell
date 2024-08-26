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

# LIBS
LIBFT		= -L$(LIBFT_PATH) -lft
LIBS		= $(LIBFT) -Wno-unused-command-line-argument

# INCLUDES
LIBFT_INC	= -I$(LIBFT_PATH)/includes
HISTORY_INC	= -Iincludes
INCLUDES	= $(LIBFT_INC) $(HISTORY_INC)

# COMPILATION CONFIG
CC		= cc -g
AR		= ar rcs
CFLAGS	= -Wall -Wextra -Werror

# FUNCTION
define Compile
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2) $(LIBS) 
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