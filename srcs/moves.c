/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:37:57 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/26 20:40:05 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		all->p = mlx_xpm_file_to_image(all->mlx_ptr,"textures/p.xpm",&all->i, &all->j);
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
		all->p = mlx_xpm_file_to_image(all->mlx_ptr,"textures/pv2.xpm",&all->i, &all->j);
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