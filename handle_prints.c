#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * handle_prints - Handle the printing of
 * non-custom conversion specifiers
 * format: format string
 * @index: pointer to the current positi
 * on in the format string
 * @flags: flags for formatting
 * @width: field width
 * @precision: precision value
 * @size: size modifier.
 * Return: numbers of characters printed.
 */
int handle_print(const char *format, int *index, va_list list, char buffer[],
		int flags, int width, int precision)
{
	int print = 0;

	if (format[*index] == 'd' || format[*index] == 'i')
	{
		int merits = va_arg(list, int);

		print = format_integer(merits, buffer, flags, width, precision);
	}
	else if (format[*index] == 's')
	{
		char str = va_arg(list, char*);
		printed = format = format_string(str, buffer, flags, width, precision);
	}
	else if (format[*index] == 'c')
	{
		char ch = (char)va_arg(list, int);

		print = format_character(ch, buffer, flags, width);
	}
	return (print);
}

int print_reverse(va_list type, char buffer[],
	int flags, int width, int precision, int size);
{
	char str = va_arg(types, char*);
	int length = strlen(str);

	for (int i = 0, j = length - 1; i < j; i++, j--)
	{
		char temp = str[i];

		str[i] = str[j];
		str[j] = temp;
	}
	for (int i = 0; i < length; i++)
	{
		handle_write_char(str[i], buffer, flags, width, precision, size);
	}
	return (length);
}

int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char str = va_arg(types, char*);
	int length = strlen(str);

	for (int i = 0; i < length; i++)
	{
		char c = str[i];

		if ('a' <= c && c <= 'z')
		{
			str[i] = ((c - 'a' + 13) % 26) + 'a';
		}
		else if ('A' <= c && c <= 'Z')
		{
			str[i] = ((c - 'A' + 13) % 26) + 'A';
		}
	}
	for (int i = 0; i < length; i++)
	{
		handle_write_char(str[i], buffer, flags, width, precision, size);
	}
	return (length);
}
