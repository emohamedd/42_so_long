/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 00:19:42 by emohamed          #+#    #+#             */
/*   Updated: 2022/10/24 03:51:34 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int n)
	{
	int	counter;

	counter = 0;
	if (n < 0)
	{
			counter += ft_putchar('-');
			n *= -1;
	}
	if (n > 9)
		counter += ft_putnbr(n / 10);
	counter += ft_putchar((n % 10) + '0');
	return (counter);
}
