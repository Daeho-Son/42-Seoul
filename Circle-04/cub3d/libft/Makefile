# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 14:21:14 by dason             #+#    #+#              #
#    Updated: 2021/01/02 23:29:29 by dason            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		= -Wall -Wextra -Werror
INC_LINK	= -I./includes/

NAME		= libft.a
DIR			= ./src/
FILES		= ft_memset.c		\
			  ft_bzero.c		\
			  ft_memcpy.c		\
			  ft_memccpy.c		\
			  ft_memmove.c		\
			  ft_memchr.c		\
			  ft_memcmp.c		\
			  ft_strlen.c		\
			  ft_strlcpy.c		\
			  ft_strlcat.c		\
			  ft_strchr.c		\
			  ft_strrchr.c		\
			  ft_strnstr.c		\
			  ft_strncmp.c		\
			  ft_atoi.c			\
			  ft_isalpha.c		\
			  ft_isdigit.c		\
			  ft_isalnum.c		\
			  ft_isascii.c		\
			  ft_isprint.c		\
			  ft_toupper.c		\
			  ft_tolower.c		\
			  ft_calloc.c		\
			  ft_strdup.c		\
			  ft_substr.c		\
			  ft_strjoin.c		\
			  ft_strtrim.c		\
			  ft_split.c		\
			  ft_itoa.c			\
			  ft_strmapi.c		\
			  ft_putchar_fd.c	\
			  ft_putstr_fd.c	\
			  ft_putendl_fd.c	\
			  ft_putnbr_fd.c
SRCS		= $(addprefix $(DIR), $(FILES))
OBJS		= $(SRCS:.c=.o)

%.o		: %.c
	@gcc $(CFLAGS) -c $< -o $@

all 	: $(NAME)

$(NAME)	: $(OBJS)
	@echo "\033[31mmake LIBFT\033[0m"
	@ar rc $(NAME) $(OBJS)

clean 	:
	@echo "\033[31mmake clean LIBFT\033[0m"
	@rm -f $(OBJS)

fclean 	:
	@echo "\033[31mmake fclean LIBFT\033[0m"
	@rm -f $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
