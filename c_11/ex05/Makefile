NAME = do-op

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

SRCS_PATH = srcs
SRCS = $(SRCS_PATH)/cal.c $(SRCS_PATH)/utils.c $(SRCS_PATH)/main.c
OBJS = $(SRCS:%.c=%.o)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re