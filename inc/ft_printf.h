#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>   
#include <unistd.h>   
#include <stdlib.h>

int ft_printf(const char *format, ...);

int print_char(char c);
int print_str(char *str);
int print_pointer(void *ptr);
int print_int(int num);
int print_unsigned(unsigned int num);
int print_hex(unsigned int num, int uppercase);

#endif
