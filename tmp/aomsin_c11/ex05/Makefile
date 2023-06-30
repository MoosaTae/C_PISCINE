NAME = do-op

SRC = main.c ft_putnbr.c

OBJS = ${SRC:.c=.o}

CC = cc -Wall -Wextra -Werror

all: ${NAME}

.c.o:
		${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${CC} -o ${NAME} ${OBJS}

clean: 
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re