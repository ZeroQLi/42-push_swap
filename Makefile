# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 18:11:16 by mtangalv          #+#    #+#              #
#    Updated: 2025/04/02 16:34:59 by zeroql           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFILES = src/push_swap.c \
	src/init_stacks.c \
	src/algo.c \
	src/init_a_to_b.c \
	utils/parsing.c \
	utils/errs.c \
	utils/list_funcs.c \
	utils/swap_operations.c \
	utils/rotate_operations.c \
	utils/push_operations.c

OBJECTS = $(CFILES:.c=.o)

LIBFT_PATH = libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: subsystems $(NAME)

subsystems:
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJECTS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAGS) -o $(NAME)

clean:
	make clean -C libft/
	rm -rf $(OBJECTS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re : fclean all

.PHONY:	all clean fclean re
