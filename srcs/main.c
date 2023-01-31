/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:53:48 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/31 10:10:14 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
	int main(int argc, char **argv)
	{
		t_map	all;

		if (argc != 2)
		{
			ft_printf("%sERROR : Bad Syntax Miss ARG%s", RED, END);
			exit(1);	
		}
		all.is_open = 0;
		all.map_path = argv[1];
		banner();
		check_file_ber(argv[1]);
		count_lines(argv[1]);
		get_map(argv[1], &all);
		valid_map(&all);
		check_map(&all);
		all_valid(&all);
		int xlen = ft_strlen(all.map[0]);
		int  ylen= count_lines(all.map_path);
		all.mlx_ptr = mlx_init();
		all.mlx_win = mlx_new_window(all.mlx_ptr, xlen*50,ylen*50, "so_long");
		draw_map(&all);
		draw_map1(&all);
		mlx_hook(all.mlx_win, 2, 0, key_hook, &all);
		mlx_hook(all.mlx_win, ON_DESTROY, 0, on_destroy, (void *)0);
		mlx_loop(all.mlx_ptr);	
	}
