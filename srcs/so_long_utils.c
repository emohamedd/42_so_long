/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:38:14 by emohamed          #+#    #+#             */
/*   Updated: 2023/02/07 19:05:19 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_lines(char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	exit_door(t_map *all)
{
	win_banner();
	ft_printf("%s\t\t\t\t\t\t\t\t NOW U ARE READY TO WIN THE WAR !!!%s\n", RED,
		END);
	ft_printf("%s\t\t\t\t\t\t\t YOUR SCORE : *- %d -* %s\n\n", GREEN,
		all->counter, END);
	exit(0);
}
