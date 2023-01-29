/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:37:43 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/29 22:55:00 by emohamed         ###   ########.fr       */
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

	all->bg = mlx_xpm_file_to_image(all->mlx_ptr,"textures/bg.xpm",&all->i, &all->j);

	if (!all->bg)
	{
		ft_printf("%sERROR :Invalid Background image%s", RED, END);
		exit(1);
	}
	all->wll = mlx_xpm_file_to_image(all->mlx_ptr,"textures/texture.xpm",&all->i, &all->j);
	if (!all->wll)
	{
		ft_printf("%sERROR :Invalid wall image%s", RED, END);
		exit(1);
	}
	all->clt = mlx_xpm_file_to_image(all->mlx_ptr,"textures/col.xpm",&all->i, &all->j);
	if (!all->clt){
		ft_printf("%sERROR :Invalid collectable image%s", RED, END);
		exit(1);
	}

	all->p = mlx_xpm_file_to_image(all->mlx_ptr,"textures/p.xpm",&all->i, &all->j);
	if (!all->p){
		ft_printf("%sERROR :Invalid player image%s", RED, END);
		exit(1);	
	}
	all->e = mlx_xpm_file_to_image(all->mlx_ptr,"textures/open.xpm",&all->i, &all->j);
	if (!all->e)
	{
		ft_printf("%sERROR :Invalid Exit image%s", RED, END);
		exit(1);
	}
	all->e2 = mlx_xpm_file_to_image(all->mlx_ptr,"textures/close.xpm",&all->i, &all->j);
	if (!all->e2)
	{
		ft_printf("%sERROR :Invalid Exit image2%s", RED, END);
		exit(1);
	}
	
}

int on_destroy(t_map *all)
{
    ft_printf("%s SUCCES : window is destroyed%s", GREEN, END);
    exit(0);
}
