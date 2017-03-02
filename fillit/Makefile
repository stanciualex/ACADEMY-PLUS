# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astanciu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 16:27:01 by astanciu          #+#    #+#              #
#    Updated: 2017/01/19 19:14:15 by astanciu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRC = src/fillit.c src/validations.c src/stock.c src/solver.c src/map.c \
	   gnl/get_next_line.c
OBJ = fillit.o validations.o stock.o solver.o map.o get_next_line.o
INCL = includes/

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I $(INCL) -c $(SRC)
	gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
