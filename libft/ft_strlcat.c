/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:46:16 by emohamed          #+#    #+#             */
/*   Updated: 2022/10/06 13:08:28 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	x;
	unsigned int	lendest;
	unsigned int	selen;

	i = 0;
	x = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[x])
	{
		x++;
	}
	lendest = x;
	selen = ft_strlen(src);
	if (size <= lendest)
		return (selen + size);
	while (src[i] && i < size - lendest - 1)
	{
		dest[x] = src[i];
		i++;
		x++;
	}
	dest[x] = '\0';
	return (lendest + selen);
}
