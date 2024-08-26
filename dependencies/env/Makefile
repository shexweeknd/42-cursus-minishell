# PROGRAM NAME
NAME		= libenv.a

# FILES
FILES		= env.c env_utils.c env_free.c

# OBJECT FILES
OBJS		= $(FILES:%.c=output/%.o)

# DEPENDENCIES
DEP_PATH	= ..
LIBFT_PATH	= $(DEP_PATH)/libft

# LIBS
LIBFT		= -L$(LIBFT_PATH) -lft
LIBS		= $(LIBFT) -Wno-unused-command-line-argument

# INCLUDES
LIBFT_INC	= -I$(LIBFT_PATH)/includes
ENV_INC		= -Iincludes
INCLUDES	= $(LIBFT_INC) $(ENV_INC)

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

$(NAME)		: $(OBJS)
				make -C $(LIBFT_PATH)
				$(call CreateLib,$^,$@)

clean		:
				rm -rf $(OBJS)

fclean		: clean
				rm -rf $(NAME)

re			: fclean all

.PHONY		: clean fclean re all