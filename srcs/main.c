/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:53:48 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/20 22:47:44 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
int main(int argc, char **argv)
{
	t_map	all;


	if (argc != 2)
		return 0;
	all.is_open = 0;
	banner();
	count_lines(argv[1]);
	all.map_path = argv[1];
	get_map(argv[1], &all);
	check_file_ber(argv[1]);
	valid_map(&all);
	
	


	int xlen = ft_strlen(all.map[0]);
	int  ylen= count_lines(all.map_path);

	exit_door(&all);
	all.mlx_ptr = mlx_init();
	all.mlx_win = mlx_new_window(all.mlx_ptr, xlen*50,ylen*50, "so_long");
	draw_map(&all);
	draw_map1(&all);
	mlx_hook(all.mlx_win, 2, 0, key_hook, &all);
	mlx_loop(all.mlx_ptr);
	
}
