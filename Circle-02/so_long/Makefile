CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit
FSANITIZE	= -fsanitize=address

MLX_DIR		= ./mlx/

LIBFT_NAME	= libft.a
LIBFT_DIR	= ./libft/
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

INC_LINK	= -I./includes/
NAME		= so_long
SRC_DIR		= ./src/
C_FILES		= func_check.c		\
			  func_error.c		\
			  func_exit.c		\
			  func_init.c		\
			  func_move1.c		\
			  func_move2.c		\
			  func_paint.c		\
			  func_view.c		\
			  get_next_line.c	\
			  load_images.c		\
			  load_map.c		\
			  main.c
SRCS		= $(addprefix $(SRC_DIR), $(C_FILES))
OBJS		= $(SRCS:.c=.o)

%.o			: %.c
	gcc -c $(CFLAGS) -Imlx $(FSANITIZE) $(INC_LINK) $< -o $@

all			: $(NAME)

$(NAME)	: $(MLX) $(LIBFT) $(OBJS)
	@echo "\033[31mmake SO_LONG\033[0m"
	gcc -g $(FSANITIZE) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(LIBFT)	:
	@make all -C $(LIBFT_DIR)

$(MLX)		:
	@echo "\033[31mmake MLX\033[0m"
	make all -C $(MLX_DIR)

clean		:
	@make clean -C $(LIBFT_DIR)
	@echo "\033[31mmake clean SO_LONG\033[0m"
	rm -f $(OBJS)

fclean		:
	@make fclean -C $(LIBFT_DIR)
	@echo "\033[31mmake fclean SO_LONG\033[0m"
	rm -f $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
