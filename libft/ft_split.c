/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:47:46 by emohamed          #+#    #+#             */
/*   Updated: 2022/10/19 17:03:03 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
			j++;
		while (s[j] && s[j] == c)
			j++;
		i++;
	}
	return (i);
}

static int	ft_len(char *s, char c)

{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char *s, char c)
{
	char	**ptr;
	int		j;

	ptr = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			ptr[j] = ft_substr(s, 0, ft_len(s, c));
			j++;
		}
		while (*s && *s != c)
			s++;
	}
	ptr[j] = NULL;
	return (ptr);
}
/* int main()
{
	char x[] = "ANA smiti amine ";
	char **words = ft_split(x, ' ');
	int  i = 0;
	while(words[i])
	{
		printf("%s\n", words[i]);
		i++;
	}
}
*/