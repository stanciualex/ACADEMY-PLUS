NAME = csv

SRCS = main.c get_data.c stock_data.c clear_data.c validations.c \
      logs.c print.c ft_itoa.c ft_isalpha.c

OBJ = main.o get_data.o stock_data.o clear_data.o validations.o \
      logs.o print.o ft_itoa.o ft_isalpha.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
    gcc -c $(FLAGS) $(SRCS)
    gcc -o $(NAME) $(OBJ)

clean:
    /bin/rm -rf $(OBJ)

flcean: clean
    /bin/rm -rf $(NAME)

re: fclean all
