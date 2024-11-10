#include "../inc/ft_printf.h"

static int handle_conversion(char specifier, va_list args)
{
    if (specifier == 'c') return print_char(va_arg(args, int));
    if (specifier == 's') return print_str(va_arg(args, char *));
    if (specifier == 'p') return print_pointer(va_arg(args, void *));
    if (specifier == 'd' || specifier == 'i') return print_int(va_arg(args, int));
    if (specifier == 'u') return print_unsigned(va_arg(args, unsigned int));
    if (specifier == 'x' || specifier == 'X') return print_hex(va_arg(args, unsigned int), specifier == 'X');
    if (specifier == '%') return write(1, "%", 1);
    return 0;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int i = 0;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            count += handle_conversion(format[i], args);
        }
        else
        {
            count += write(1, &format[i], 1);
        }
        i++;
    }
    va_end(args);
    return count;
}
