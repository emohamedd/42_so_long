/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_1_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:27:29 by emohamed          #+#    #+#             */
/*   Updated: 2023/02/08 19:30:26 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	func(t_map *all, int x, int y)
{
	x = 0;
	while (all->map[y][x])
	{
		if (all->map[y][x] == '1')
			mlx_put_image_to_window(all->mlx_ptr, all->mlx_win, all->wll, x
				* 50, y * 50);
		else if (all->map[y][x] == 'C')
			mlx_put_image_to_window(all->mlx_ptr, all->mlx_win, all->clt, x
				* 50, y * 50);
		else if (all->map[y][x] == 'P')
			mlx_put_image_to_window(all->mlx_ptr, all->mlx_win, all->p, x * 50,
				y * 50);
		else if (all->map[y][x] == 'E')
		{
			if (!all->is_open)
				mlx_put_image_to_window(all->mlx_ptr, all->mlx_win, all->e, x
					* 50, y * 50);
			else
				mlx_put_image_to_window(all->mlx_ptr, all->mlx_win, all->e2, x
					* 50, y * 50);
		}
		x++;
	}
}

void	loop_map(t_map *all, int x, int y)
{
	while (all->map[y])
	{
		func(all, x, y);
		y++;
	}
}
