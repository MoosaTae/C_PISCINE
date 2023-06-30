# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moetienn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 14:43:12 by moetienn          #+#    #+#              #
#    Updated: 2023/06/27 16:58:51 by moetienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = includes/ft.h

MY_SRC = srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_putstr.c srcs/ft_putchar.c srcs/ft_swap.c

MY_OBJECTS = $(MY_SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c -I $(INC) $< -o $(<:.c=.o)

$(NAME) : $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)
	ranlib $(NAME)

all : $(NAME)

clean : 
	rm -f $(MY_OBJECTS) 

fclean :	clean
	rm -f  $(NAME)

re:	fclean all
