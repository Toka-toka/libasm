# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sedric <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 17:29:46 by sedric            #+#    #+#              #
#    Updated: 2021/02/09 23:56:10 by sedric           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRC = 	ft_strlen.s\
		ft_strcmp.s\
		ft_strcpy.s\
		ft_write.s\
		ft_read.s\
		ft_strdup.s

OBJ = $(SRC:.s=.o)

%.o: %.s
	nasm -f macho64 $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) test_main test test1

re: fclean all

test:	$(NAME)
		gcc main.c $(NAME) -o test_main && ./test_main

.PHONY: all clean fclean re