#include "../inc/ft_printf.h"

size_t ft_strlen(const char *str)
{
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}