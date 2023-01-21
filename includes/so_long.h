/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:05:57 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/20 22:43:55 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define	SO_LONG_H
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "../libft/libft.h"
#include "get_next_line.h"
#include "../ft_printf/ft_printf.h"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"

# define W_KEY 13
# define A_KEY 0
# define D_KEY 2
# define S_KEY 1
# define UP_KEY 126
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define ESC_KEY 53
typedef struct map
{
	char **map;
	char *map_path;
	int rows;
	int cols;
	int player_x;
	int player_y;
	int coin_counter;
	int cnt_c;
	int left_pos;
	void	*mlx_ptr;
	void	*mlx_win;
	void *bg;
	void *wll;
	void *clt;
	void *p;
	void *e;
	void *e2;
	int is_open;
	int i;
	int j;
	int counter ;
}t_map;


int count_lines(char* filename);
int valid_map(t_map *all);
int count_lines(char* filename);
void	get_map(char *file_name, t_map *all);
int check_map(t_map *all);
void move_down(t_map *all);
void move_up(t_map *all);
void move_left(t_map *all);
void move_right(t_map *all);
void draw_map(t_map *all);
void draw_map1(t_map *all);
int key_hook(int keycode, t_map *all);
void banner(void);
void coin_count(t_map *all);
int check_file_ber(char* file_name);
void exit_door(t_map *all);
#endif