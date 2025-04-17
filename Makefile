# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtangalv <mtangalv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 18:11:16 by mtangalv          #+#    #+#              #
#    Updated: 2025/04/14 21:03:59 by mtangalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFILES = src/push_swap.c \
	src/init_stacks.c \
	src/algo.c \
	src/algo_operations.c \
	src/init_a_to_b.c \
	src/move_a_to_b.c \
	src/init_b_to_a.c \
	src/move_b_to_a.c \
	utils/parsing.c \
	utils/errs.c \
	utils/list_funcs.c \
	utils/more_list_funcs.c \
	utils/swap_operations.c \
	utils/rotate_operations.c \
	utils/push_operations.c

OBJECTS = $(CFILES:.c=.o)

LIBFT_PATH = libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: subsystems $(NAME)

subsystems:
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJECTS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAGS) -o $(NAME)

clean:
	@make clean -C $(LIBFT_PATH)
	rm -rf $(OBJECTS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re : fclean all

.PHONY:	all clean fclean re
