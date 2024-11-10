#include "../inc/ft_printf.h"

static void print_hex_pointer(unsigned long ptr)
{
    if (ptr >= 16)
        print_hex_pointer(ptr / 16);
    write(1, &"0123456789abcdef"[ptr % 16], 1);
}

int print_pointer(void *ptr)
{
    unsigned long address = (unsigned long)ptr;
    int count = write(1, "0x", 2);
    if (address == 0)
        count += write(1, "0", 1);
    else
        print_hex_pointer(address);
    return count;
}
