/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:37:43 by emohamed          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:29 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_map1(t_map *all)
{
	int	x;
	int	y;
	int	xlen;
	int	ylen;

	y = 0;
	x = 0;
	xlen = ft_strlen(all->map[0]);
	ylen = count_lines(all->map_path);
	while (x <= ylen)
	{
		y = 0;
		while (y <= xlen)
		{
			mlx_put_image_to_window(all->mlx_ptr, all->mlx_win, all->bg, y * 50,
				x * 50);
			y++;
		}
		x++;
	}
	y = 0;
	loop_map(all, x, y);
}

void	draw_map(t_map *all)
{
	all->bg = mlx_xpm_file_to_image(all->mlx_ptr, "textures/bg.xpm", &all->i,
			&all->j);
	if (!all->bg)
		printf_message("ERROR :Invalid Background image");
	all->wll = mlx_xpm_file_to_image(all->mlx_ptr, "textures/texture.xpm",
			&all->i, &all->j);
	if (!all->wll)
		printf_message("ERROR :Invalid wall image");
	all->clt = mlx_xpm_file_to_image(all->mlx_ptr, "textures/key.xpm", &all->i,
			&all->j);
	if (!all->clt)
		printf_message("ERROR :Invalid collectable image");
	all->p = mlx_xpm_file_to_image(all->mlx_ptr, "textures/p.xpm", &all->i,
			&all->j);
	if (!all->p)
		printf_message("ERROR :Invalid player image");
	all->e = mlx_xpm_file_to_image(all->mlx_ptr, "textures/open.xpm", &all->i,
			&all->j);
	if (!all->e)
		printf_message("ERROR :Invalid Exit image");
	all->e2 = mlx_xpm_file_to_image(all->mlx_ptr, "textures/close.xpm", &all->i,
			&all->j);
	if (!all->e2)
		printf_message("ERROR :Invalid Exit image2");
}

int	on_destroy(void)
{
	ft_printf("%s SUCCES : window is destroyed%s", GREEN, END);
	exit(0);
}
