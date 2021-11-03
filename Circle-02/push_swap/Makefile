# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dason <dason@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 18:01:28 by dason             #+#    #+#              #
#    Updated: 2021/07/05 14:56:09 by dason            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		= -Wall -Wextra -Werror

INC_LINK	= -I./includes/

LIBFT_NAME	= libft.a
LIBFT_DIR	= ./libft/
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

PS_NAME		= push_swap
PS_DIR		= ./src/push_swap/
PS_SRCS_NAME= push_swap.c				\
			  func_arr.c				\
			  sort_stack.c				\
			  sort_two_three.c			\
			  sort_three_plus.c			\
			  sort_four_five.c			\
			  sort_above_seven.c		\
			  sort_above_seven_util.c

PS_SRCS		= $(addprefix $(PS_DIR), $(PS_SRCS_NAME))
PS_OBJS		= $(PS_SRCS:.c=.o)

CM_DIR		= ./src/common/
CM_SRC_NAME	= commands.c			\
			  error_check.c			\
			  init_stack.c			\
			  func_base.c			\
			  func_command.c		\
			  check_sort_status.c	\
			  free_all.c
CM_SRCS		= $(addprefix $(CM_DIR), $(CM_SRC_NAME))
CM_OBJS		= $(CM_SRCS:.c=.o)


%.o			: %.c
	@gcc $(CFLAGS) -c $(INC_LINK) $< -o $@ 


all			: $(PS_NAME)

$(PS_NAME)	: $(LIBFT) $(PS_OBJS) $(CM_OBJS)
	@echo "make push_swap"
	@gcc -g $(CFLAGS) $(PS_OBJS) $(CM_OBJS) $(LIBFT) -o $(PS_NAME) 

$(LIBFT)	:
	@make all -C $(LIBFT_DIR)

clean		:
	@make clean -C $(LIBFT_DIR)
	@echo "clean push_swap"
	@rm -f $(PS_OBJS)
	@echo "clean common"
	@rm -f $(CM_OBJS)

fclean		:
	@make fclean -C $(LIBFT_DIR)
	@echo "fclean push_swap"
	@rm -f $(PS_NAME)

re			: fclean all

.PHONY		: all clean fclean re
