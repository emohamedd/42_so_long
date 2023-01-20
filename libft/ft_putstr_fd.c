/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:15:23 by emohamed          #+#    #+#             */
/*   Updated: 2022/10/21 10:06:20 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], sizeof(s[i]));
			i++;
		}
	}
}

// #include <fcntl.h>
// int main()
// {
// 	int	fd;

// 	fd = open("test.txt", O_CREAT | O_RDWR, 777);
// 	write(fd,"TESTTESTTES",11);
// }
