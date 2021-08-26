SRC_DIR	= src/

OBJ_DIR = objs/

DEP_DIR	= ./includes

SRCS	= ft_bsq.c ft_display.c ft_first_lines.c ft_compute_tab.c ft_resolve_map.c ft_read_map.c ft_read_stdin.c main.c

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I$(DEP_DIR)

NAME	= bsq

all:		$(OBJ_DIR) $(NAME)


$(OBJ_DIR)%.o: 		$(SRC_DIR)%.c
			$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
			mkdir -p $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			rm -rf $(OBJ_DIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re	
