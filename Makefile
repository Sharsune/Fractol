# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharsune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 18:29:57 by sharsune          #+#    #+#              #
#    Updated: 2023/01/10 18:29:58 by sharsune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = fractol.c mlx_handlers.c calculations.c movescreen.c

OSRC = $(SRC:%.c=%.o)

WWW = -Wall -Wextra -Werror

all:  $(NAME)

$(NAME): $(OSRC)
	cc $(WWW) $(OSRC) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

%.o: %.c
	cc $(WWW) -c -o $@ $^ 

re: fclean all

.PHONY: all clean fclean re
