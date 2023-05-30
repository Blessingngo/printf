#include "main.h"
#include <stdarg.h>
#include <stdio.h>
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
	return (-1);
	va_start(args, format);
	while (*format)
{
	if (*format == '%')
{
	format++;
	switch (*format)
{
	case 'c':
	putchar(va_arg(args, int));
	count++;
	break;
	case 's':
{
	const char *str = va_arg(args, const char *);

	while (*str)
{
	putchar(*str++);
	count++;
}
	break;
}
	case '%':
	putchar('%');
	count++;
	break;
}
}
	else
{
	putchar(*format);
	count++;
}
	format++;
}
	va_end(args);
	return (count);
}
