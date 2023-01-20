/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:15:00 by emohamed          #+#    #+#             */
/*   Updated: 2022/10/24 03:46:15 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_adress(long long unsigned int n, char *b)
{
	int	cnt;

	cnt = 0;
	if (cnt >= 16)
	{
		cnt += ft_adress(n / 16, b);
		cnt += ft_adress(n % 16, b);
	}
	else
		cnt += ft_putchar(b[n]);
	return (cnt);
}
