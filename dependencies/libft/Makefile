# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 11:14:27 by ballain           #+#    #+#              #
#    Updated: 2024/10/18 13:13:45 by hramaros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
SRCS		= \
				ft_atoi.c				\
				ft_isvar.c				\
				ft_isalpha.c			\
				ft_memchr.c				\
				ft_strchr.c				\
				ft_strlcpy.c			\
				ft_strrchr.c			\
				ft_bzero.c				\
				ft_isascii.c			\
				ft_memcmp.c				\
				ft_strdup.c				\
				ft_strlen.c				\
				ft_strtrim.c			\
				ft_calloc.c				\
				ft_isdigit.c			\
				ft_isnbr.c 				\
				ft_memcpy.c				\
				ft_striteri.c			\
				ft_strmapi.c			\
				ft_substr.c				\
				ft_isprint.c			\
				ft_memmove.c			\
				ft_strjoin.c			\
				ft_strncmp.c			\
				ft_tolower.c			\
				ft_isalnum.c			\
				ft_itoa.c				\
				ft_memset.c				\
				ft_split.c				\
				ft_strlcat.c			\
				ft_strnstr.c			\
				ft_toupper.c			\
				ft_putchar_fd.c			\
				ft_putendl_fd.c			\
				ft_putnbr_fd.c			\
				ft_putstr_fd.c			\
				ft_isset.c 				\
				ft_isdecimal.c			\
				ft_strcmp.c				\
				get_next_line.c			\
				get_next_line_utils.c	\
				ft_lst_utils.c			\
				ft_get_occ.c			\
				ft_is_only_spaces.c		\
				ft_getlen_strtab.c		\
				ft_str_replace.c		\
				ft_join.c				\
				ft_nl_to_zero.c			\
				ft_is_quote.c			\
				ft_is_cmd_sep.c			\
				ft_is_redirect.c		\
				ft_is_delimiter.c		\
				ft_skip_space.c			\
				get_ps_two.c			\
				ft_nblen.c				\
				ft_perror_fd.c

SRCSBONUS	= \
	ft_lstnew_bonus.c	ft_lstadd_front_bonus.c	ft_lstsize_bonus.c	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	ft_lstclear_bonus.c	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c	ft_lstjoin.c

OBJS		= $(SRCS:%.c=output/%.o)
OBJSBONUS	= $(SRCSBONUS:%.c=output/%.o)
CFLAGS		= -Wall -Wextra -Werror -Iincludes
RM			= rm -rf
CC			= cc -g

all 		: bonus

output		:
				@if [ ! -d output ]; then mkdir output; fi

output/%.o	: functions/%.c | output
				$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)		: $(OBJS)
				ar rc $(NAME) $^

bonus		: $(NAME) $(OBJSBONUS)
				ar rc $(NAME) $^

norme		:
				norminette

clean 		:
				$(RM) $(OBJS) $(OBJSBONUS)

vimclean	:
				$(RM) $(VIMFILE)

fclean		: clean
				$(RM) $(NAME)

cleanall	: fclean vimclean
re			: fclean all
.PHONY		: fclean clean all bonus
