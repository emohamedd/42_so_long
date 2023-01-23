/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:37:43 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/23 13:54:07 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void draw_map1(t_map *all)
{
	int x; 
	int y;
	y = 0;
	x = 0;
	int xlen = ft_strlen(all->map[0]);
	int  ylen= count_lines(all->map_path);
	while(x <= ylen)
	{
		y = 0;
		while(y <= xlen)
		{
			mlx_put_image_to_window(all->mlx_ptr, all->mlx_win, all->bg, y*50,x*50);
			y++;
		}
		x++;
	}
	y = 0;
	while(all->map[y])
	{
		x = 0;
		while (all->map[y][x]){
			if (all->map[y][x] == '1')
			{
				mlx_put_image_to_window(all->mlx_ptr, all->mlx_win, all->wll, x*50,y*50);	
			}
				else if (all->map[y][x] == 'C')
			{
				mlx_put_image_to_window(all->mlx_ptr, all->mlx_win, all->clt, x*50,y*50);	
			}
				else if (all->map[y][x] == 'P')
			{
				mlx_put_image_to_window(all->mlx_ptr, all->mlx_win, all->p, x*50,y*50);	
			}
			else if (all->map[y][x] == 'E')
			{
				if (!all->is_open)
					mlx_put_image_to_window(all->mlx_ptr, all->mlx_win, all->e, x*50,y*50);	
				else
					mlx_put_image_to_window(all->mlx_ptr, all->mlx_win, all->e2, x*50,y*50);	
			}
			x++;
		}
		y++;	
	}
}
void draw_map(t_map *all)
{
	int x = 0;
	int y = 0;

	all->bg = mlx_xpm_file_to_image(all->mlx_ptr,"players/bg.xpm",&all->i, &all->j);

	if (!all->bg)
	{
		ft_printf("%sERROR :Invalid Background image%s", RED, END);
		exit(1);
	}
	all->wll = mlx_xpm_file_to_image(all->mlx_ptr,"players/texture.xpm",&all->i, &all->j);
	if (!all->wll)
	{
		ft_printf("%sERROR :Invalid wall image%s", RED, END);
		exit(1);
	}
	all->clt = mlx_xpm_file_to_image(all->mlx_ptr,"players/col.xpm",&all->i, &all->j);
	if (!all->clt){
		ft_printf("%sERROR :Invalid collectable image%s", RED, END);
		exit(1);
	}

	all->p = mlx_xpm_file_to_image(all->mlx_ptr,"players/p.xpm",&all->i, &all->j);
	if (!all->p){
		ft_printf("%sERROR :Invalid player image%s", RED, END);
		exit(1);	
	}
	all->e = mlx_xpm_file_to_image(all->mlx_ptr,"players/e.xpm",&all->i, &all->j);
	if (!all->e)
	{
		ft_printf("%sERROR :Invalid Exit image%s", RED, END);
		exit(1);
	}
	all->e2 = mlx_xpm_file_to_image(all->mlx_ptr,"players/e2.xpm",&all->i, &all->j);
	if (!all->e2)
	{
		ft_printf("%sERROR :Invalid Exit image2%s", RED, END);
		exit(1);
	}
	
}
void move_right(t_map *all)
{
	if (all->map[all->player_x][all->player_y + 1] != '1' && all->map[all->player_x][all->player_y + 1] != 'E')
	{
		if ( all->map[all->player_x][all->player_y + 1] == 'C')
		{
			all->coin_counter +=1;
		if (all->cnt_c == all->coin_counter)
			all->is_open = 1;
			// ft_printf("%d\n", all->coin_counter);	
		}
		all->counter +=1;
		all->map[all->player_x][all->player_y] = '0';
		all->player_y += 1;
		all->map[all->player_x][all->player_y] = 'P';
		all->p = mlx_xpm_file_to_image(all->mlx_ptr,"players/p.xpm",&all->i, &all->j);
		ft_printf(" * --> Moves = %d%s\n", all->counter,  YELLOW, END);
	}
		exit_door(all);
}
void move_left(t_map *all)
{
	if (all->map[all->player_x][all->player_y - 1] != '1' && all->map[all->player_x][all->player_y - 1] != 'E')
	{
		if ( all->map[all->player_x][all->player_y - 1] == 'C')
		{
			all->coin_counter +=1;
			if (all->cnt_c == all->coin_counter)
				all->is_open = 1;
			// ft_printf("%d\n", all->coin_counter);
		}
		all->counter +=1;
		all->map[all->player_x][all->player_y] = '0';
		all->player_y -= 1;
		all->map[all->player_x][all->player_y] = 'P';
		all->p = mlx_xpm_file_to_image(all->mlx_ptr,"players/pv2.xpm",&all->i, &all->j);
		ft_printf(" * --> Moves = %d%s\n", all->counter,  YELLOW, END);
	}
			exit_door(all);
}
void move_up(t_map *all)
{
	if (all->map[all->player_x - 1][all->player_y] != '1' && all->map[all->player_x - 1][all->player_y] != 'E')
	{
		if ( all->map[all->player_x - 1][all->player_y] == 'C')
		{
			all->coin_counter +=1;
			if (all->cnt_c == all->coin_counter)
				all->is_open = 1;
			// ft_printf("%d\n", all->coin_counter);
		}
		all->counter +=1;
		all->map[all->player_x][all->player_y] = '0';
		all->player_x -= 1;
		all->map[all->player_x][all->player_y] = 'P';
		ft_printf(" * --> Moves = %d%s\n", all->counter,  YELLOW, END);
	}
			exit_door(all);
}
void move_down(t_map *all)
{
	if (all->map[all->player_x + 1][all->player_y] != '1' && all->map[all->player_x + 1][all->player_y] != 'E')
	{
		if ( all->map[all->player_x + 1][all->player_y] == 'C')
		{
			all->coin_counter +=1;
			if (all->cnt_c == all->coin_counter)
				all->is_open = 1;
			// ft_printf("%d\n", all->coin_counter);
		}
		all->counter +=1;
		all->map[all->player_x][all->player_y] = '0';
		all->player_x += 1;
		all->map[all->player_x][all->player_y] = 'P';
		ft_printf(" * -->  Moves = %d%s\n", all->counter,  YELLOW, END);
	}
		exit_door(all);
		
}
int key_hook(int keycode, t_map *all)
{	
	if (keycode == W_KEY || keycode ==UP_KEY )
	{
    	move_up(all);
		draw_map1(all);
	} 
    else if (keycode == S_KEY || keycode ==DOWN_KEY)
	{ 
    	move_down(all);
		draw_map1(all);
	} 
    else if (keycode == A_KEY || keycode ==LEFT_KEY)
	{

		move_left(all);
		draw_map1(all);
	} 
    else if (keycode == D_KEY || keycode ==RIGHT_KEY)
	{

		move_right(all);
		draw_map1(all);
	} 
	else if (keycode == ESC_KEY)
	{
		ft_printf("%s SUCCES : window is destroyed%s", GREEN, END);
		mlx_destroy_window( all->mlx_ptr, all->mlx_win);
		exit(0);			
	}

	return 1;
}
int on_destroy(t_map *all)
{
    ft_printf("%s SUCCES : window is destroyed%s", GREEN, END);
    exit(0);
}
