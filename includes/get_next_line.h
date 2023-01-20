/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:42:58 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/17 19:06:32 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
#include "../libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_v2(char *s1, char *s2);
char	*new_get_exact_line(char *line);
char	*new_get_line(char *str, int fd);
int		check_str(char *buff);
char	*ft_strchr_v2(char *string, char nl);

#endif