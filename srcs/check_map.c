/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map->map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:50:43 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/17 20:02:42 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

    
int check_map(t_map *all)
{

    int cnt_pt = 0;
    int cnt_e = 0;
    all->cnt_c = 0;
    int d = 0;
    int i = 0;
    int j = 0;
    while(ft_strlen(all->map[0]) == ft_strlen(all->map[d]))
    {
        d++;
        if (all->map[d] == NULL )   
            break;   
    }
    // all->map[i][j] != 'E' && all->map[i][j] != 'P'  && all->map[i][j] != 'C' && all->map[i][j] != '1' && all->map[i][j] != '0'
    while (i < all->rows - 1)
    {
        while (j < all->cols)
        {
            if (!ft_strchr("01ECP", all->map[i][j]))
            {   
                ft_printf("%s%s ERROR :  The Map Should Contain Only 01ECP", RED, END);
                return 0;
            }
            else if (all->map[i][j] == 'P')
            {
                cnt_pt++;
                all->player_x = i;
                all->player_y = j;
            }
             else if (all->map[i][j] == 'E')
            {
                cnt_e++;
            } 
            else if (all->map[i][j] == 'C')
            {
                all->cnt_c++;
            }
            j++;
        }
        i++;
        j = 0;
    }

    if (cnt_pt != 1 || cnt_e != 1 || all->cnt_c < 1 || d != all->rows - 1) {
        return 0;
    }
    return 1;
}

int valid_map(t_map *all)
{

    int col = 0;
	
    int check_maps = check_map(all);
    int check = 0;
    int map_width = ft_strlen(all->map[0]);
    int map_height = count_lines(all->map_path);

    col = map_width - 1;
    while (col >= 0)
    {
        if (all->map[0][col] != '1')
           check = 1;
        col--;
    }
    col = map_width - 1;
    while (col >= 0)
    {
        if (all->map[map_height - 1][col] != '1')
            check = 1;
        col--;
    }
    int row = 0;
    while (row < map_height)
    {
        if (all->map[row][0] != '1')
            check = 1;
        row++;
    }
    row = 0;
    while (row < map_height)
    {
        if (all->map[row][map_width - 1] != '1')
            check = 1; 
        row++;
    }
    if(check == 1 || !check_maps)
    {
        ft_printf("%sERROR : Invalid Map%s\n", RED, END);
        exit(1);
    }
   ft_printf("%s SUCCES : Map is valid %s\n", GREEN, END);
        return 1;
}
