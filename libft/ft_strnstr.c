/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:55:20 by emohamed          #+#    #+#             */
/*   Updated: 2022/10/21 09:51:54 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!haystack && !needle) || ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			while (i + j < len && needle[j] && haystack[j + i] == needle[j])
				j++;
			if (j == ft_strlen(needle))
				return ((char *)(haystack + i));
			j = 0;
		}
		i++;
	}
	return (NULL);
}
// int main()
// {
// 	char hay[] = "smiti amine";
// 	char need[] = "hlf blah";
// 	size_t len = 5;
// 	printf("%s",ft_strnstr(hay,need,len));
// }
