#include "../inc/ft_printf.h"

int print_str(char *str)
{
    if (!str) 
        return write(1, "(null)", 6);
    return write(1, str, strlen(str));
}
