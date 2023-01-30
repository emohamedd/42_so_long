# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:59:05 by emohamed          #+#    #+#              #
#    Updated: 2023/01/30 12:45:11 by emohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc

CFLAGS 	= -Wall -Werror -Wextra 

SRCS = srcs/get_next_line.c srcs/get_next_line_utils.c srcs/so_long_utils.c srcs/so_long.c srcs/get_map.c srcs/check_map.c\
 srcs/main.c srcs/banner.c srcs/check_name.c srcs/moves.c srcs/valid_path.c

NAME = so_long

OBJS = $(SRCS:.c=.o)
SRCS_DIR = ./srcs
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RED			=   \033[0;31m
RESET		=	\e[0m
_RUN	=	$(GREEN) *- SUCCES : READY TO PLAY -* $(RESET)
_FAIL	=	$(RED) * - WARN : MAKE TO RUN THE GAME -* $(RESET)

%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $^

all : $(NAME)


$(NAME) : $(OBJS)
	make -C libft/ all
	make -C ft_printf/ all
	$(CC)  $(CFLAGS) $^ -L./libft  -lft -L./ft_printf -lftprintf -lmlx -framework OpenGL -framework AppKit -o $@
	@printf "\t\t\t\t\t$(_RUN)\n"

clean:
	make -C libft/ clean
	make -C ft_printf/ clean
	rm $(OBJS)
	@printf "\t\t\t\t\t$(_FAIL)\n"

fclean : clean
	make -C libft/ fclean
	make -C ft_printf/ fclean
	rm $(NAME)
	@printf "\t\t\t\t\t$(_FAIL)\n"

re : fclean all
	@printf "\t\t\t\t\t$(_RUN)\n"

rungame : 
	./so_long maps/1337.ber

.PHONY: all clean fclean re


