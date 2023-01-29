/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:05:33 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/29 04:43:54 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_map_rec(t_map *all)
{
	if (all->map[all->player_y][all->player_x] == '1' || all->map[all->player_y][all->player_x] == 'E')
	return;
	else
		all->map[all->player_y][all->player_x] == '1';
	check_map_rec(all->map[all->player_y][all->player_x + 1]);
	check_map_rec(all->map[all->player_y - 1][all->player_x]);
	check_map_rec(all->map[all->player_y][all->player_x - 1]);
	check_map_rec(all->map[all->player_y + 1][all->player_x]);
}

int map_path(t_map *all)
{
	all->cols = 0;
	while(all->map[all->cols])
	{
		all->rows = 0;
		while(all->map[all->cols][all->rows])
		{
			if (all->map[all->cols][all->rows] != '1' &&all->map[all->cols][all->rows] != 'E')
			{
				return 0;
			}
			all->rows++;
		}
		all->cols++;
	}
	return 1;
}
	int all_valid(t_map *all)
{
		
}