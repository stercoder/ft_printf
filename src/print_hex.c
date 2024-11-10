#include "../inc/ft_printf.h"

static int print_hex_number(unsigned int n, int uppercase)
{
    int count = 0;

    if (n >= 16)
        count += print_hex_number(n / 16, uppercase);

    if (uppercase)
        count += write(1, &"0123456789ABCDEF"[n % 16], 1); // Uppercase hex characters
    else
        count += write(1, &"0123456789abcdef"[n % 16], 1); // Lowercase hex characters

    return count;
}

int print_hex(unsigned int num, int uppercase)
{
    if (num == 0)
        return write(1, "0", 1);  // Directly return count if printing "0"
    
    return print_hex_number(num, uppercase);
}
