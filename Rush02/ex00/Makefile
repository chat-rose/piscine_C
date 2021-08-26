SRC_DIR	= src/

OBJ_DIR = bin/

DEP_DIR	= ./includes

SRCS	= main.c rush02.c init.c utils.c ft_split.c free.c file.c utils2.c find_dict.c find_dict2.c

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I$(DEP_DIR)

NAME	= rush-02

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
