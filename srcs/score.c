/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:54:59 by emohamed          #+#    #+#             */
/*   Updated: 2023/02/06 15:19:26 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int score_store(t_map *all)
{
	char *score;
	score = NULL;
	if (all->fd == -1)
	{
		ft_printf("%s ERROR : File Descriptor Error%s\n", RED , END);
		exit(1);
	}
	ft_printf("wa zbi elach : %s", score);
	score = get_next_line(all->fd);
	printf("%d \n " , all->fd);
	ft_printf("wa zbi elach : %s", score);
	if (ft_atoi(score) >= all->counter)
	{
		write(all->fd, ft_itoa(all->counter), 1);
			ft_printf("%s\t\t\t\t\t NEW HIGH SCORE !!!! : %d%s\n", GREEN, all->counter, END);
	}
	else
	{
		write(all->fd, score, sizeof(score));
    	ft_printf("%s\t\t\t\t\t\t\t TOP SCORE :  *- %s -* %s\n\n", GREEN, score, END);
    	ft_printf("%s\t\t\t\t\t\t\t YOUR SCORE : *- %d -* %s\n\n", GREEN, all->counter, END);
	}
	close(all->fd);
	exit(0);
}