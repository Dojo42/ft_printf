# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thofaure <thofaure@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 11:02:10 by thofaure          #+#    #+#              #
#    Updated: 2024/11/26 11:06:44 by thofaure         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra
OBJ=$(SRC:.c=.o)
HEADER=ft_printf.h
SRC=ft_itoa_hexa.c\
	ft_itoa.c\
	ft_printf_hexa.c\
	ft_printf_utils.c\
	ft_printf.c

NAME=libftprintf.a

all: $(NAME)

$(NAME):$(OBJ) $(HEADER)
	ar -rcs $(NAME) $(OBJ)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -I . -c $< -o $@
	
.PHONY:clean fclean re bonus all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
