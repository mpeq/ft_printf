# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpequeno <mpequeno@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:59:39 by mpequeno          #+#    #+#              #
#    Updated: 2021/12/16 11:48:34 by mpequeno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printers.c ft_printf.c

NAME = libftprintf.a

OBJ = $(SRC:%.c=%.o)

AR = ar rcs

RM = rm -f

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) 
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re rebonus
