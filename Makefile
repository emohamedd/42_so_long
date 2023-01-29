# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:59:05 by emohamed          #+#    #+#              #
#    Updated: 2023/01/29 23:56:26 by emohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

CFLAGS 	= -Wall -Werror -Wextra 

SRCS = srcs/get_next_line.c srcs/get_next_line_utils.c srcs/so_long_utils.c srcs/so_long.c srcs/get_map.c srcs/check_map.c ft_printf/ft_adress.c \
ft_printf/ft_hexa.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putnbru.c ft_printf/ft_putstr.c srcs/main.c srcs/banner.c \
srcs/check_name.c srcs/moves.c

NAME = so_long

OBJS = $(SRCS:.c=.o)

GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RED			=   \033[0;31m
RESET		=	\e[0m
_RUN	=	$(GREEN) *- SUCCES : READY TO PLAY -* $(RESET)
_FAIL	=	$(RED) * - WARN : MAKE TO RUN THE GAME -* $(RESET)

all : $(NAME)

$(NAME) : $(SRCS)
	make -C libft/ all
	make -C ft_printf/ all
	$(CC)  $^ -L./libft  -lft -lmlx -framework OpenGL -framework AppKit -o $@
	@printf "\t\t\t\t\t$(_RUN)\n"

clean:
	make -C libft/ clean
	make -C ft_printf/ clean
	rm $(OBJS)
	@printf "\t\t\t\t\t$(_FAIL)\n"

fclean : 
	make -C libft/ fclean
	make -C ft_printf/ fclean
	rm $(NAME)
	@printf "\t\t\t\t\t$(_FAIL)\n"

re : fclean all
	@printf "\t\t\t\t\t$(_RUN)\n"

.PHONY: all clean fclean re


