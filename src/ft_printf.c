/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhindou <ykhindou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:47:24 by ykhindou          #+#    #+#             */
/*   Updated: 2024/11/10 18:59:00 by ykhindou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <unistd.h>

int	safe_write(int fd, const char *buf, size_t count)
{
	ssize_t	ret;

	ret = write(fd, buf, count);
	if (ret == -1)
		return (-1);
	return (ret);
}

static int	handle_conversion(char specifier, va_list args)
{
	if (specifier == 'c')
		return (print_char(va_arg(args, int)));
	if (specifier == 's')
		return (print_str(va_arg(args, char *)));
	if (specifier == 'p')
		return (print_pointer(va_arg(args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (print_int(va_arg(args, int)));
	if (specifier == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	if (specifier == 'x' || specifier == 'X')
		return (print_hex(va_arg(args, unsigned int), specifier == 'X'));
	if (specifier == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_format(const char *format, va_list args)
{
	int	i;
	int	count;
	int	tmp;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			tmp = handle_conversion(format[i], args);
			if (tmp == -1)
				return (-1);
			count += tmp;
		}
		else
			count += safe_write(1, &format[i], 1);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!format)
		return (-1);
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(args, format);
	count = ft_format(format, args);
	va_end(args);
	return (count);
}

// else
// {
// 	tmp = safe_write(1, &format[i], 1);
// 	if (tmp == -1)
// 	{
// 		va_end(args);
// 		return (-1);
// 	}
// 	count += tmp;
// }