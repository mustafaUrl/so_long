# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muraler <muraler@student.42.tr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 14:30:30 by muraler           #+#    #+#              #
#    Updated: 2022/05/17 14:30:36 by muraler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRC = $(shell find . -name "ft_*.c")

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC)
	ar rc $(NAME) *.o
clean:
	rm -f  *.o
fclean: clean
	rm -f $(NAME)

re: fclean all
