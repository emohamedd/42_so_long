/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:56:00 by emohamed          #+#    #+#             */
/*   Updated: 2022/10/21 09:51:02 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (dst >= src)
		while (len--)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
// int main()
// {
// 	int i = 0;
// 	int  src[6]={1,1,3,4,5,6};
// 	int dst[] = {2,3,4};
// 	char *s;
// 	s = ft_memmove(dst,src,5);
// 	while (i < 3)
// 	{
// 	printf("%d ",dst[i]);
// 	i++;
// 	}
// }	
