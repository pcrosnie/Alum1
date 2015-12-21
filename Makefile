# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/21 18:05:49 by pcrosnie          #+#    #+#              #
#    Updated: 2015/12/21 18:14:07 by pcrosnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

SRC = ft_reserve.c ft_read.c ft_play.c ft_alum1.c libft.a

CC = gcc

O = -o

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): 
	$(CC) $(O) $(NAME) $(SRC)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all re clean fclean
