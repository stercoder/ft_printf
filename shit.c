#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
char	is_format(char c)
{
	char *form = "csdpiuxX";
	while(*form)
	{
		if (*form == c)
			return (c);
		form++;
	}
	return ('0');
}

int	count_args(char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s == '%')
			count++;
		s++;
	}
	return (count);
}

int	testft(char *s, ...)
{
	va_list args;
	int total_args;

	total_args = count_args(s);
	va_start(args, total_args);
	return (0);
}















int	main()
{
	char *s = "don't";
	int d = 0;
	char c = 'o';
	testft("mine : string: %s. integer d: %d. character : %c", s, d, c);
	 printf("Standard: string: %s. integer d: %d. character : %c", s, d, c);

	return (0);
}