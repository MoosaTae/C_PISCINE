NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = main.c \
			ft_checkvalid.c \
			ft_dict.c \
			ft_output.c \
			ft_read.c \
			ft_read2.c \
			memory.c
OBJ_FILES = $(SRC_FILES:.c=.o)

$(NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) $^ -o $(NAME)
	
all: $(NAME)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re