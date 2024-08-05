# PROGRAM NAME
NAME		= libenv.a

# FILES
FILES		= env.c env_utils.c env_free.c

# DEPENDENCIES
DEP_PATH	= ..
LIBFT_PATH	= $(DEP_PATH)/libft

# OBJECT FILES
OBJS		= $(FILES:%.c=output/%.o)

# INCLUDES
LIBFT_INC	= -I$(LIBFT_PATH)
ENV_INC		= -Iincludes
INCLUDES	= $(LIBFT_INC) $(ENV_INC)


# COMPILATION CONFIG
CC		= cc -g
AR		= ar rcs
CFLAGS	= -Wall -Wextra -Werror $(INCLUDES)

# FUNCTION
define Compile
	$(CC) $(CFLAGS) -c $(1) -o $(2)
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

libft		:
				make -C $(LIBFT_PATH)

$(NAME)		: libft $(OBJS)
				$(call CreateLib,$^,$@)

clean		:
				rm -rf $(OBJS)

fclean		: clean
				rm -rf $(NAME)

re			: fclean all

.PHONY		: clean fclean re all