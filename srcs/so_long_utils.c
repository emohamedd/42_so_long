/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:38:14 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/21 08:26:25 by emohamed         ###   ########.fr       */
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
