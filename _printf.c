#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int count = 0;
	const char *ptr = format;

	while (*ptr != '\0')
{
	if (*ptr == '%')
{
	ptr++;
	if (*ptr == 'c')
{
	int ch = va_arg(args, int);

	putchar(ch);
}
	else if (*ptr == 's')
{
	const char *str = va_arg(args, const char *);

	while (*str != '\0')
{
	putchar(*str);
	str++;
}
}
	else if (*ptr == '%')
{
	putchar('%');
}
}
	else
{
	putchar(*ptr);
}
	ptr++;
}
	va_end(args);
	return (count);
}
