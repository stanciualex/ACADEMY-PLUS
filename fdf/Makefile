# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astanciu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 15:49:46 by astanciu          #+#    #+#              #
#    Updated: 2017/02/11 13:45:16 by astanciu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
SRC = src/fdf.c src/mlx.c src/display.c src/iso.c src/hook.c src/hook2.c \
	  src/aux.c
OBJ = fdf.o mlx.o display.o iso.o hook.o hook2.o aux.o
INCL = include/
all: $(NAME)

$(NAME):
	make -C ./libft
	gcc $(FLAGS) -I $(INCL) -c $(SRC)
	gcc $(OBJ) libft/libft.a -o $(NAME) $(MLX)

clean:
	make -C ./libft clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C ./libft fclean
	/bin/rm -rf $(NAME)

re: fclean all
	
