# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moetienn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 13:30:23 by moetienn          #+#    #+#              #
#    Updated: 2023/06/21 17:16:01 by moetienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc -Wall -Werror -Wextra -c ft_strlen.c ft_strcmp.c ft_putstr.c ft_putchar.c ft_swap.c
ar -rc libft.a ft_strlen.o ft_strcmp.o ft_putstr.o ft_putchar.o ft_swap.o
rm -rf *.o
