/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:57:30 by emohamed          #+#    #+#             */
/*   Updated: 2022/10/21 09:51:07 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = (unsigned char *)b;
	while (i < len)
	{
		mem[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
// int main()
// {
// 	int i = 0;
// 	int	tab[5]={18,45,12,16,66};
// 	int c = 45;
// 	char	*s;
// 	s = ft_memset(tab, c, 3);
// 	while (i < 5)
// 	{
// 		printf("%d ", s[i++]);
// 	}
// }
