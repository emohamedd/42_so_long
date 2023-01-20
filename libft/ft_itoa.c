/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:09:43 by emohamed          #+#    #+#             */
/*   Updated: 2022/10/19 15:44:48 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbrlen(int n)
{
	int	cnt;

	cnt = 0;
	if (n <= 0)
		cnt++;
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*str;
	long int	x;

	x = (long int)n;
	i = nbrlen(n) - 1;
	str = malloc(sizeof(char) * (nbrlen(n) + 1));
	if (!str)
		return (0);
	if (x == 0)
		str[0] = x + 48;
	if (x < 0)
	{
		str[0] = '-';
		x = -x;
	}
	while (x)
	{
		str[i] = (x % 10) + 48;
		x = x / 10;
		i--;
	}
	str[nbrlen(n)] = '\0';
	return (str);
}
