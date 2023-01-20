/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:55:07 by emohamed          #+#    #+#             */
/*   Updated: 2022/10/19 01:05:38 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	s;
	void	*ptr;

	s = count * size;
	ptr = malloc(s);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, s);
	return (ptr);
}
