/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhindou <ykhindou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:32:52 by ykhindou          #+#    #+#             */
/*   Updated: 2024/11/10 16:44:05 by ykhindou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	print_unsigned_number(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += print_unsigned_number(n / 10);
	count += write(1, &"0123456789"[n % 10], 1);
	return (count);
}

int	print_unsigned(unsigned int num)
{
	return (print_unsigned_number(num));
}
