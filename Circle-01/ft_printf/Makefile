# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 20:02:09 by dason             #+#    #+#              #
#    Updated: 2021/07/06 16:28:02 by dason            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		= -Wall -Wextra -Werror
INC_LINK	= -I./includes/

LIBFT_NAME	= libft.a
LIBFT_DIR	= ./libft/
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

NAME		= libftprintf.a
DIR			= ./src/
FILES		= ft_printf.c			\
			  find_parse_format.c	\
			  ft_printf_utils.c		\
			  format_c_per.c		\
			  format_s.c			\
			  format_ux.c			\
			  format_di.c			\
			  format_p.c
SRCS		= $(addprefix $(DIR), $(FILES))
OBJS		= $(SRCS:.c=.o)

%.o		: %.c
	gcc $(CFLAGS) -c $(INC_LINK) $< -o $@

all		: $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rc  $(NAME) $(OBJS)

clean	:
	@make clean -C $(LIBFT_DIR)
	@echo "clean FT_PRINTF"
	@rm -rf $(OBJS)

fclean	:
	@make fclean -C $(LIBFT_DIR)
	@echo "fclean FT_PRINTF"
	@rm -f $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
