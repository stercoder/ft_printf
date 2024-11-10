#include <stdio.h>
#include <stdarg.h>
#include <string.h> 
#include <string.h> 
#include <unistd.h>
#include <stdlib.h>
#include "tot.c"


// void  word_argument(char *str, void *p)
// {
//     char **format_specifier = {"\%s", "\%c", "%\p", "\%d", "\%i" "\%u", "\%x", "\%X", "\%%"};
//     char **type_argument = {"char", "char*", "void*", "int", "unsigned int"};
   
// }

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int    ft_putstr(char *s)
{
    int i;
    i = 0;
    while (s[i]){
        ft_putchar(s[i]);
        i++;
    }
    return (i);
}

char *ft_pointer(void *ptr) {
    static char buffer[18];  // Large enough for "0x" prefix and hex representation
    unsigned long long addr = (unsigned long long)ptr;
    char *hex_digits = "0123456789abcdef";
    int i = 17;

    buffer[i--] = '\0';  // Null-terminate
    if (addr == 0) {
        buffer[i--] = '0';  // Special case for NULL pointer (0x0)
    } else {
        // Convert the address to hex, storing from the end towards the beginning
        while (addr > 0) {
            buffer[i--] = hex_digits[addr % 16];
            addr /= 16;
        }
    }
    // Add "0x" prefix
    buffer[i--] = 'x';
    buffer[i] = '0';

    // Return the pointer to where the string starts
    return &buffer[i];
}

char    *ft_hex_to_str(int n, char format) //format x for smallhex and X for bighex
{
    static char    buffer[12];
    char *small_hex= "0123456789abcdef";
    char *big_hex = "0123456789ABCDEF";

    int i;
    i = 10;
    buffer[11] = '\0';
    while (n)
    {
        buffer[i]= small_hex[(n % 16) + '0'];
        n = n / 16;
        i--;
    }

    buffer[i--] = 'x';
    buffer[i] = '0';
    return (&buffer[0]);
}

char is_format_specifier(char c)
{
    char *s = "scdpiuxX%"; 
    while (*s)
    {
        if(*s == c)
            return (c);
        s++;
    }
    return (0);
}
 
 int    count_args(char *s)
 {
    int count = 0;
    int i = 0;
    while (s[i])
    {
        if (s[i] == '%' && (is_format_specifier(s[i + 1]) != 0))
        {
            count++;
            i++;
        }
        i++;
    }
    return (count);
 }




int    f1(char *s,...)
{
    va_list args;
    char *salut = s;
    int total_length;

    total_length = 0;
    // char *specifies= "cspdiuxX%";
    // char *my_args;
    int i;
    i = 0;
    int c = count_args(s);
    printf("\n %d +=====================\n", c);
    va_start(args, s); 
    int j = 0;
    while(s[j])
    {
        // && s[j] == '%' && (is_format_specifier(s[j + 1]) != '0')

        if (i < c && s[j] == '%' && is_format_specifier(s[j + 1]) != '0')
        {
            
            // word_argument(salut, va_arg(args, char *));
            if (is_format_specifier(s[j + 1]) == 's')
                 total_length += ft_putstr(va_arg(args, char *));

            if (is_format_specifier(s[j + 1]) == 'c')
                 total_length += ft_putchar((char)va_arg(args, int)); 

            if (is_format_specifier(s[j + 1]) == 'd')
                 total_length += ft_putstr(ft_itoa((va_arg(args, int))));

            if (is_format_specifier(s[j + 1]) == 'i')
                 total_length += ft_putstr(ft_itoa((va_arg(args, int))));


            if (is_format_specifier(s[j + 1]) == 'u')
                 total_length += ft_putstr(ft_itoa((va_arg(args, int))));

            if (is_format_specifier(s[j + 1]) == 'p')
                 total_length += ft_putstr(ft_pointer((va_arg(args, void *))));

            if (is_format_specifier(s[j + 1]) == '%')
                total_length += ft_putchar('%');
            i++;
            j++;
        }
        else
             total_length += write(1, &s[j], 1);
        j++;
    }

    va_end(args);
    return total_length;
}
int main()
{
    char *s1 = "test1";
    char *s2 = "test2";
    char *s3 = "test3";
    char c1 = 'a';
    char c2 = 'Z';
    char c3 = '2';
    int c4 = -555; 
    int c5 = 4343;
    int c6 = -42; 

        f1("->%s.--> %c ->%d. ->%u--- %% --> %i || %p.\n", s1, c2, c4, c5, c6, &"78"); 
    printf("->%s.--> %c ->%d. ->%u--- %% --> %i || %p.\n", s1, c2, c4, c5, c6, &"78");  
     ft_putchar('\n'); 

     int num = 6703;
     printf("Lowercase hex: %x\n", num); // Output: Lowercase hex: 1a3f
     printf("Uppercase hex: %X\n", num); // Output: Uppercase hex: 1A3F


    // printf("hell0 %s", "world");
    return (0);
}