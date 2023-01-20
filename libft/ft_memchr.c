/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:58:46 by emohamed          #+#    #+#             */
/*   Updated: 2022/10/21 09:50:39 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
// int main()
// {
// 	int i = 0;
// 	char	tab[20]={1,2,3,4,5};
// 	// int c = 2;
// 	char	*s;
// 	s = ft_memchr(tab, 2, 3);
// 	while (i < 2)
// 	{
// 		printf("%d", s[i]);
// 		i++;
// 	}
// }