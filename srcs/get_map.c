/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:24:32 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/17 23:48:14 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map(char *file_name, t_map *all)
{
    int fd;
    char *line;
    all->map = NULL;
    int i;
	char *getstore;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        return ;
	getstore = get_next_line(fd);
    all->cols = ft_strlen(getstore);
	if (getstore[0] == '\n')
		exit(0);
    i = 1;
    while (getstore != NULL)
	{
		line = ft_strjoin_v2(line, getstore);
		getstore = get_next_line(fd);
        i++;
    }
    all->rows = i;
	all->map = ft_split(line, '\n');
    close(fd);
        free(line);
}
