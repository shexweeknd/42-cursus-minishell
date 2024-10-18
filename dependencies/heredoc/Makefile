# PROGRAM NAME
NAME		= libhd.a

# FILES
FILES		= hd.c \
			hd_utils.c \

FUNC_FILES	= eof.c \
			to_hd.c \
			get_doc.c \
			hd_err.c \
			hd_sig.c \
			hd_cleaner.c \
			hd_debug.c \

# SRC FILES
FUNC		= $(FUNC_FILES:%.c=functions/%.c)

# OBJECT FILES
OBJS		= $(FILES:%.c=output/%.o)
FUNC_OBJS	= $(FUNC:functions/%.c=output/%.o)

# DEPENDENCIES
DEP_PATH	= ..
LIBFT_PATH	= $(DEP_PATH)/libft
ERR_PATH	= $(DEP_PATH)/err
STATIC_PATH	= $(DEP_PATH)/static
SIG_PATH	= $(DEP_PATH)/sig

# INCLUDES
HD_INC		= -Iincludes
TEMPLATES	= -I$(DEP_PATH)/templates
LIBFT_INC	= -I$(LIBFT_PATH)/includes
ERR_INC		= -I$(ERR_PATH)/includes
STATIC_INC	= -I$(STATIC_PATH)/includes
SIG_INC		= -I$(SIG_PATH)/includes
INCLUDES	= \
				$(TEMPLATES)	\
				$(LIBFT_INC)	\
				$(ERR_INC)		\
				$(STATIC_INC)	\
				$(SIG_INC)	\
				$(HD_INC)

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
all			: $(NAME) | tmp

tmp			:
				@if [ ! -d tmp ]; then mkdir tmp; fi

output		:
				@if [ ! -d output ]; then mkdir output; fi

output/%.o	: %.c | output
				$(call Compile,$<,$@)

output/%.o	: functions/%.c | output
				$(call Compile,$<,$@)

$(NAME)		: $(OBJS) $(FUNC_OBJS)
				make -C $(LIBFT_PATH)
				$(call CreateLib,$^,$@)

clean		:
				rm -rf tmp
				rm -rf $(OBJS)
				rm -rf $(FUNC_OBJS)

fclean		: clean
				rm -rf $(NAME)

re			: fclean all

.PHONY		: clean fclean re all