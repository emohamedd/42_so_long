/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:54:35 by emohamed          #+#    #+#             */
/*   Updated: 2022/10/03 14:54:53 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*i;

	i = (char *)s;
	while (*i)
	{
		if (*i == (char)c)
			return (i);
		i++;
	}
	if (*i == (char)c)
		return (i);
	return (NULL);
}
