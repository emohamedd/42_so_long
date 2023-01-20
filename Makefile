# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:59:05 by emohamed          #+#    #+#              #
#    Updated: 2023/01/20 15:21:46 by emohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

#CFLAGS 	= -Wall -Werror -Wextra 

SRCS = srcs/get_next_line.c srcs/get_next_line_utils.c srcs/so_long_utils.c srcs/so_long.c srcs/get_map.c srcs/check_map.c ft_printf/ft_adress.c \
ft_printf/ft_hexa.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putnbru.c ft_printf/ft_putstr.c srcs/main.c srcs/banner.c \
srcs/check_name.c 

NAME = so_long

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS)
	make -C libft/ all
	make -C ft_printf/ all
	$(CC) $^ -L./libft  -lft -lmlx -framework OpenGL -framework AppKit -o $@

clean:
	make -C libft/ clean
	make -C ft_printf/ clean
	rm $(OBJS)

fclean : 
	make -C libft/ fclean
	make -C ft_printf/ fclean
	rm $(NAME)

re : fclean all



