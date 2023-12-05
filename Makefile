#####################################################

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = ft_printf.h
AR = ar rcs

SRC = ft_printf.c ft_printf_char.c ft_printf_digit.c \
		ft_printf_string.c 

OBJ = $(SRC:.c=.o)

#####################################################

%.o: %.c
	$(CC) -o $@ -c $^

all : $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re