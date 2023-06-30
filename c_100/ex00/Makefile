NAME = ft_display_file

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

SRCS_DIR = srcs
SRCS = $(SRCS_DIR)/ft_putchar.c $(SRCS_DIR)/ft_putstr.c $(SRCS_DIR)/ft_display_file.c main.c
OBJS = $(SRCS:%.c=%.o)
FILE = tests/file.txt
RUN		= ./${NAME}

%.o:%.c
	$(CC) $(CFLAGS) ${INCLUDES} -c $< -o $@ 

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

all: $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

file:
	@echo "It's_my_time!" > $(FILE)

test: $(NAME) file
	@$(RUN) $(FILE)

.PHONY: all clean fclean re file test