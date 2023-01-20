/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:31:01 by emohamed          #+#    #+#             */
/*   Updated: 2022/10/20 12:11:45 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	aminepape(char *str, int *ptr_i)
{
	long	count;
	int		i;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			count *= -1;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi(char *str)
{
	long	sign;
	long	result;
	int		i;

	result = 0;
	sign = aminepape(str, &i);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}
// int main()
// {
// 	char str[]="99";
// 	printf(" original atoi is -------> : %d\n", atoi(str));
// 	printf("my atoi is -------> : %d", ft_atoi(str));
// }