/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhindou <ykhindou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:50:05 by ykhindou          #+#    #+#             */
/*   Updated: 2024/11/10 19:00:07 by ykhindou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>   
# include <unistd.h>   
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		print_char(char c);
int		print_str(char *str);
int		print_pointer(void *ptr);
int		print_int(int num);
int		print_unsigned(unsigned int num);
int		print_hex(unsigned int num, int uppercase);
size_t	ft_strlen(const char *str);

#endif
