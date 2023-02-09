# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharsune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 18:29:57 by sharsune          #+#    #+#              #
#    Updated: 2023/01/23 13:45:47 by sharsune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = libft.a

SRC = fractol.c mlx_handlers.c movescreen.c calculations.c zoom.c arguments.c

OSRC = $(SRC:%.c=%.o)

WWW = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OSRC)
	cc $(WWW) $(OSRC) -L libft/ -lft -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean:
	rm -f $(OSRC)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/$(LIBFT)

%.o: %.c
	cc $(WWW)  -g -c -o  $@ $^ 

re: fclean all

.PHONY: all clean fclean re