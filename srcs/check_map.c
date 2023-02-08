/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:50:43 by emohamed          #+#    #+#             */
/*   Updated: 2023/02/08 19:49:52 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ini(t_check_map *check)
{
	check->cnt_pt = 0;
	check->cnt_e = 0;
	check->d = 0;
	check->i = 0;
	check->j = 0;
}

int	check_map(t_map *all)
{
	t_check_map	check;

	ini(&check);
	all->cnt_c = 0;
	while (ft_strlen(all->map[0]) == ft_strlen(all->map[check.d]))
	{
		check.d++;
		if (all->map[check.d] == NULL)
			break ;
	}
	while (check.i < all->rows - 1)
	{
		while (check.j < all->cols)
		{
			if (!ft_strchr("01ECP", all->map[check.i][check.j]))
			{
				ft_printf("%sERROR :  The Map Should Contain Only 01ECP%s\n",
					RED, END);
				return (0);
			}
			else if (all->map[check.i][check.j] == 'P')
			{
				check.cnt_pt++;
				all->player_x = check.i;
				all->player_y = check.j;
			}
			else if (all->map[check.i][check.j] == 'E')
			{
				check.cnt_e++;
			}
			else if (all->map[check.i][check.j] == 'C')
			{
				all->cnt_c++;
			}
			check.j++;
		}
		check.i++;
		check.j = 0;
	}
	if (check.cnt_pt != 1 || check.cnt_e != 1 || all->cnt_c < 1
		|| check.d != all->rows - 1)
	{
		ft_printf("%s ERROR : P < 1 || E < 1 || !C%s\n", RED, END);
		return (0);
	}
	return (1);
}

int	valid_map(t_map *all)
{
	t_valid_map	map;

	map.col = 0;
	map.check = 0;
	map.check_maps = check_map(all);
	map.map_width = ft_strlen(all->map[0]);
	map.map_height = count_lines(all->map_path);
	map.col = map.map_width - 1;
	while (map.col >= 0)
	{
		if (all->map[0][map.col] != '1')
			map.check = 1;
		map.col--;
	}
	map.col = map.map_width - 1;
	while (map.col >= 0)
	{
		if (all->map[map.map_height - 1][map.col] != '1')
			map.check = 1;
		map.col--;
	}
	map.row = 0;
	while (map.row < map.map_height)
	{
		if (all->map[map.row][0] != '1')
			map.check = 1;
		map.row++;
	}
	map.row = 0;
	while (map.row < map.map_height)
	{
		if (all->map[map.row][map.map_width - 1] != '1')
			map.check = 1;
		map.row++;
	}
	if (map.check == 1 || !map.check_maps)
	{
		ft_printf("%sERROR : Invalid Map%s\n", RED, END);
		exit(1);
	}
	ft_printf("%s SUCCES : Map is valid %s\n", GREEN, END);
	return (1);
}
