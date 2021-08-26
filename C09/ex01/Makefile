SRC			= srcs/ft_putchar.c \
			srcs/ft_swap.c \
			srcs/ft_putstr.c \
			srcs/ft_strlen.c \
			srcs/ft_strcmp.c

OBJS		= ${SRC:.c=.o}

NAME		= libft.a

AR			= ar rc

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -Iincludes

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
					${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
				rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
