CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
MLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX_NAME	= libmlx.a
MLX_DIR		= ./mlx/
MLX			= $(addprefix $(MLX_DIR), $(MLX_NAME))

LIBFT_NAME	= libft.a
LIBFT_DIR	= ./libft/
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

NAME		= cub3D
INC_LINK	= -I./includes/
SRC_DIR		= ./src/
C_FILES		= draw_minimap.c					\
			  draw_pixel.c						\
			  get_next_line.c					\
			  get_next_line_utils.c				\
			  key_hook.c						\
			  key_hook2.c						\
			  main.c							\
			  parse_map.c						\
			  parser_check_type_data.c			\
			  parser_get_file_data.c			\
			  parser_get_map_data.c				\
			  parser_get_map.c					\
			  parser_get_type_data.c			\
			  parser_store_file_data.c			\
			  parser_utils.c					\
			  raycast_utils.c					\
			  raycast.c							\
			  render.c							\
			  utils.c							\
			  vec2.c
SRCS		= $(addprefix $(SRC_DIR), $(C_FILES))
OBJS		= $(SRCS:.c=.o)

%.o			: %.c
	gcc -c $(CFLAGS) -Imlx $(INC_LINK) $< -o $@

all			: $(NAME)

bonus		: all

$(NAME)		: $(MLX) $(LIBFT) $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) $(MLX) -o $(NAME) $(LFLAGS)

$(LIBFT)	:
	@make all -C $(LIBFT_DIR)

$(MLX)		:
	@make all -C $(MLX_DIR)

clean		:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean		: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re			: fclean all

.PHONY		: all bonus clean fclean re
