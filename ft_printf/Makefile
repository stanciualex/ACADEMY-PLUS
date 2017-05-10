# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astanciu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/02 18:26:22 by astanciu          #+#    #+#              #
#    Updated: 2017/03/02 18:31:38 by astanciu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra -Iinclude -c
NAME = libftprintf.a
CC = gcc
_SRC = ft_printf.c handle_flags.c handle_specifiers1.c handle_specifiers2.c \
		print_csd.c print_poh.c print_wc.c print_aux.c utils.c colors.c
SRC = $(patsubst %.c, src/%.c, $(_SRC))
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC)) 

all: $(NAME)

$(OBJ): | obj

obj:
	mkdir -p $@

obj/%.o: src/%.c
	$(CC) $(FLAGS) $< -o $@

libft/libft.a:
	make -C libft/

$(NAME): libft/libft.a $(OBJ)
	cp $< $(NAME)
	ar rc $(NAME) $^
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all