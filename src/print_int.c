#include "../inc/ft_printf.h"

static int print_number(int n)
{
    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return 11;
    }
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        return print_number(n / 10) + write(1, &"0123456789"[n % 10], 1);
    return write(1, &"0123456789"[n % 10], 1);
}

int print_int(int num)
{
    return print_number(num);
}
