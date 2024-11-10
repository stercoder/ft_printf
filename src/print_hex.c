/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhindou <ykhindou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:07:26 by ykhindou          #+#    #+#             */
/*   Updated: 2024/11/10 16:11:06 by ykhindou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	print_hex_number(unsigned int n, int uppercase)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += print_hex_number(n / 16, uppercase);
	if (uppercase)
		count += write(1, &"0123456789ABCDEF"[n % 16], 1);
	else
		count += write(1, &"0123456789abcdef"[n % 16], 1);
	return (count);
}

int	print_hex(unsigned int num, int uppercase)
{
	if (num == 0)
		return (write(1, "0", 1));
	return (print_hex_number(num, uppercase));
}
