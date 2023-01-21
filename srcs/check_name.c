/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:55:43 by emohamed          #+#    #+#             */
/*   Updated: 2023/01/21 12:23:21 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
	
int check_file_ber(char* file_name)
 {
	  int len = ft_strlen(file_name);
    if (ft_strncmp(file_name + (len - 4), ".ber", 4) == 0)
			return 1;
	else 
	{
		ft_printf("%sERROR : The string does not end with .ber%s\n", RED, END);
			exit(1);
	}
		
    return 0;
}
