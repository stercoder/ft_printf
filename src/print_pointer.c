/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhindou <ykhindou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:18:04 by ykhindou          #+#    #+#             */
/*   Updated: 2024/11/10 16:25:07 by ykhindou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <unistd.h>

static int	print_hex_pointer(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr >= 16)
		count += print_hex_pointer(ptr / 16);
	count += write(1, &"0123456789abcdef"[ptr % 16], 1);
	return (count);
}

int	print_pointer(void *ptr)
{
	unsigned long	address;
	int				count;

	address = (unsigned long)ptr;
	count = write(1, "0x", 2);
	if (address == 0)
		count += write(1, "0", 1);
	else
		count += print_hex_pointer(address);
	return (count);
}
