CLFAGS		= -Wall -Wextra -Werror
INC_LINK	= -I./includes/

LIBFT_NAME	= libft.a
LIBFT_DIR	= ./libft/
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

CL_NAME		= client
CL_DIR		= ./src/client/
CL_FILES	= client.c			\
			  client_utils.c
CL_SRCS		= $(addprefix $(CL_DIR), $(CL_FILES))
CL_OBJS		= $(CL_SRCS:.c=.o)

S_NAME		= server
S_DIR		= ./src/server/
S_FILES		= server.c			\
			  server_utils.c
S_SRCS		= $(addprefix $(S_DIR), $(S_FILES))
S_OBJS		= $(S_SRCS:.c=.o)

CO_DIR		= ./src/common/
CO_FILES	= error.c
CO_SRCS		= $(addprefix $(CO_DIR), $(CO_FILES))
CO_OBJS		= $(CO_SRCS:.c=.o)

%.o			: %.c
	@gcc $(CFLAGS) -c $(INC_LINK) $< -o $@

all			: $(CL_NAME) $(S_NAME)

$(CL_NAME)	: $(LIBFT) $(CL_OBJS) $(CO_OBJS)
	@echo "make CLIENT"
	@gcc -g $(CL_OBJS) $(CO_OBJS) $(LIBFT) -o $(CL_NAME)

$(S_NAME)	: $(LIBFT) $(S_OBJS) $(CO_OBJS)
	@echo "make SERVER"
	@gcc -g $(S_OBJS) $(CO_OBJS) $(LIBFT) -o $(S_NAME)

$(LIBFT)	:
	@make all -C $(LIBFT_DIR)

clean		:
	@make clean -C $(LIBFT_DIR)
	@echo "make clean CLIENT"
	@rm -f $(CL_OBJS)
	@echo "make clean SERVER"
	@rm -f $(S_OBJS)
	@rm -f $(CO_OBJS)

fclean		:
	@make fclean -C $(LIBFT_DIR)
	@echo "make fclean CLIENT"
	@rm -f $(CL_NAME)
	@echo "make fclean SERVER"
	@rm -f $(S_NAME)

re			: fclean all

.PHONY		: all clean fclean re
