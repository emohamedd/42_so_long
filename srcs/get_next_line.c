/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:44:20 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/30 10:05:27 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"


int	check_str(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*new_get_line(char *str, int fd)
{
	int		r;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	while (1)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == 0)
			break ;
		if (r == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[r] = '\0';
		str = ft_strjoin_v2(str, buff);
		if (check_str(str) == 1)
			break ;
	}
	free(buff);
	return (str);
}

char	*new_get_exact_line(char *line)
{
	char	*extline;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	extline = malloc(i + 2);
	if (!extline)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		extline[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		extline[i] = '\n';
		i++;
	}
	extline[i] = '\0';
	return (extline);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*p;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = new_get_line(save, fd);
	p = save;
	line = new_get_exact_line(save);
	if (!line)
		return (NULL);
	save = ft_strchr_v2(save, '\n');
	free(p);
	return (line);
}
