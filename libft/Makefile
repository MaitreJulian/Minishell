# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 13:22:33 by jowoundi          #+#    #+#              #
#    Updated: 2025/09/01 18:42:51 by jvenkata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_atoi.c ft_itoa.c\
		ft_bzero.c \
		ft_calloc.c ft_realloc.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_isspace.c\
		ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_strlen.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_strnstr.c\
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c\
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_split.c\
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		get_next_line.c get_next_line_utils.c \
		ft_number_printf.c ft_printf.c ft_putstr_printf.c\
		ft_char_percent_printf.c

OBJS =	$(SRC:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar rcs
INCLUDE = -I .

all: $(NAME)

.o:.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:	
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re