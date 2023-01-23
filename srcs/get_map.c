/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:24:32 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/21 18:16:11 by emohamed         ###   ########.fr       */
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
        ft_printf("%sERROR : Failed to open file %s\n", RED, END); ;
	getstore = get_next_line(fd);
    if (!getstore)
    {
       ft_printf("%sERROR : Empty MAP%s\n", RED, END); 
        exit(1);
    }
    if (getstore[0] == '\n')
    {
        ft_printf("%sERROR : There is a Empty String on MAP%s\n", RED, END);
    }   
    all->cols = ft_strlen(getstore);
	if (getstore[0] == '\n')
		exit(0);
    i = 1;
    while (getstore != NULL)
	{
		line = ft_strjoin_v2(line, getstore);
        free(getstore);
		getstore = get_next_line(fd);
        i++;
    }
    all->rows = i;
	all->map = ft_split(line, '\n');
    close(fd);
        free(line);
}
