NAME = libft.a

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

INCLUDE = includes

CC = cc

CFLAG = -Wall -Wextra -Werror

LIBC = ar rc

LIBR = ranlib

RM = rm -f

OBJECT = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAG} -c $< -o ${<:.c=.o} -I ${INCLUDE} 

${NAME}: ${OBJECT}
	${LIBC} ${NAME} ${OBJECT}
	${LIBR} ${NAME}

all: 
	${NAME}

clean: 
	${RM} ${OBJECT}

fclean: clean
	${RM} ${NAME}

re: fclean all
