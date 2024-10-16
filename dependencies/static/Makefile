# PROGRAM NAME
NAME			= libstatic.a

# FILES
FILES			= \
					ft_senv.c		\
					ft_rootpath.c	\
					ft_rootpath.c	\
					ft_hdpath.c		\
					ft_histpath.c	\
					ft_status.c		\
					ft_sig.c 		\
					ft_statics.c

# OBJECT FILES
OBJS			= $(FILES:%.c=output/%.o)
FUNC_OBJS		= $(FUNC:functions/%.c=output/%.o)

# DEPENDENCIES
DEP_PATH		= ..
LIBFT_PATH		= $(DEP_PATH)/libft

# INCLUDES
STATIC_INC		= -Iincludes
TEMPLATES		= -I$(DEP_PATH)/templates
LIBFT_INC		= -I$(LIBFT_PATH)/includes
INCLUDES		= \
					$(TEMPLATES)	\
					$(LIBFT_INC)	\
					$(STATIC_INC)

# COMPILATION CONFIG
CC				= cc -g
AR				= ar rcs
CFLAGS			= -Wall -Wextra -Werror

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
				$(call CreateLib,$^,$@)

clean		:
				rm -rf $(OBJS)
				rm -rf $(FUNC_OBJS)

fclean		: clean
				rm -rf $(NAME)

re			: fclean all

.PHONY		: clean fclean re all