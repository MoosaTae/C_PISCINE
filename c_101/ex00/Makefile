NAME = ft_display_file

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs
SRCS = main.c
OBJS = $(SRCS:%.c=%.o)
FILE = tests/file.txt
RUN		= ./${NAME}

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

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