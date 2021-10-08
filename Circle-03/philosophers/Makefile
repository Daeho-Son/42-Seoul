# CFLAGS		= -Wall -Wextra -Werror
CFLAGS		= 
FSANITIZE	= -fsanitize=address

INC_LINK	= -I./includes/
NAME		= philo
SRC_DIR		= ./src/
C_FILES		= func_init.c		\
			  main.c
SRCS		= $(addprefix $(SRC_DIR), $(C_FILES))
OBJS		= $(SRCS:.c=.o)

%.o			: %.c
	gcc -c $(CFLAGS) $(FSANITIZE) $(INC_LINK) $< -o $@

all			: $(NAME)

$(NAME)	: $(OBJS)
	@echo "\033[31mmake PHILO\033[0m"
	gcc -g $(FSANITIZE) $(OBJS) -o $(NAME)

clean		:
	@echo "\033[31mmake clean PHILO\033[0m"
	rm -f $(OBJS)

fclean		:
	@echo "\033[31mmake fclean PHILO\033[0m"
	rm -f $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
