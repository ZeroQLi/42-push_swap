NAME = push_swap

COMP = cc

FLAGS = -Wall -Werror -Wextra

SRC = push_swap.c \

OFILES = $(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(COMP) $(FLAGS) -o $@ -c $<

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
