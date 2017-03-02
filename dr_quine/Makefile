# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astanciu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/19 18:44:11 by astanciu          #+#    #+#              #
#    Updated: 2017/01/19 19:32:07 by astanciu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
FLAGS = -Wall -Wextra -Werror
NAME1 = Colleen
NAME2 = Grace
NAME3 = Sully
GRACEFILE = $(NAME2)/Grace_kid.c
SULLYFILE = $(NAME3)/Sully_0.c $(NAME3)/Sully_1.c $(NAME3)/Sully_2.c \
			$(NAME3)/Sully_3.c $(NAME3)/Sully_4.c

all: colleen grace sully

colleen:
	$(CC) $(FLAGS) $(NAME1)/$(NAME1).c -o $(NAME1)/$(NAME1)
	
grace:
	$(CC) $(FLAGS) $(NAME2)/$(NAME2).c -o $(NAME2)/$(NAME2)

sully:
	$(CC) $(FLAGS) $(NAME3)/$(NAME3).c -o $(NAME3)/$(NAME3)

clean:
	/bin/rm -rf $(NAME1)/$(NAME1).o
	/bin/rm -rf $(NAME2)/$(NAME2).o
	/bin/rm -rf $(NAME3)/$(NAME3).o

fclean: clean
	/bin/rm -rf $(NAME1)/$(NAME1)
	/bin/rm -rf $(NAME2)/$(NAME2)
	/bin/rm -rf $(NAME3)/$(NAME3)
	/bin/rm -rf $(GRACEFILE)
	/bin/rm -rf $(SULLYFILE)

re: fclean all
