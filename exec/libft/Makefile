# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 13:22:33 by jowoundi          #+#    #+#              #
#    Updated: 2025/08/12 18:05:45 by jvenkata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c \
	ft_toupper.c ft_tolower.c \
	ft_strncmp.c ft_strcmp.c ft_strdup.c\
	ft_atoi.c ft_itoa.c \
	ft_substr.c ft_strjoin.c ft_split.c


OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror


all:
	echo $(SRC)
	$(MAKE) $(NAME)


$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
