/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:38:14 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/29 23:22:56 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
int count_lines(char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
		return 0;
	}
    int lines = 0;
    char* line;
	line = get_next_line(fd);
    while (line) {
        lines++;
        free(line); 
		line = get_next_line(fd);
    }
    close(fd);
    return lines;
}
void exit_door(t_map *all)
{
	// if ((all->map[all->player_x][all->player_y + 1] == 'E' && all->is_open == 1 )
	// || (all->map[all->player_x][all->player_y - 1] == 'E' && all->is_open == 1) || 
	// (all->map[all->player_x - 1][all->player_y] == 'E' && all->is_open == 1) ||
	//  (all->map[all->player_x + 1][all->player_y] == 'E' && all->is_open ==1))
    //  {  
    win_banner();
    ft_printf("%s\t\t\t\t\t\t\t NEW SCORE : *- %d -* %s\n\n", GREEN, all->counter, END); 
    ft_printf("%s\t\t\t\t\t\t\t\t NOW U ARE READY TO WIN THE WAR !!!%s\n", RED, END); 
    exit(0);
    //  }
}
    