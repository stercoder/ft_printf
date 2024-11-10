#include "../inc/ft_printf.h"

static int print_unsigned_number(unsigned int n)
{
    if (n >= 10)
        return print_unsigned_number(n / 10) + write(1, &"0123456789"[n % 10], 1);
    return write(1, &"0123456789"[n % 10], 1);
}

int print_unsigned(unsigned int num)
{
    return print_unsigned_number(num);
}
