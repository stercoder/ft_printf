#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
// #include "test.c"
char	*ft_itoa_ptr(void *ptr)
{
    char *s;

    printf("==> %s .\n", (char *)ptr);

}

int main()
{
    int p = 19;
    uintptr_t v = (uintptr_t)&p;

    // ft_itoa_ptr(&p);
    // int v = p;
    // printf("%d \n", v);

    printf("%d \n", 189);
    return (0);
}