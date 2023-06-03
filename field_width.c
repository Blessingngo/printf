#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * get_width: Get the field width
 * specified in the format string.
 * @format: Format string.
 * @index: Its the pointer to the
 * current position in the string.
 * Va_list: For the variable argume
 * nts.
 * Return: field width value.
 */
int get_width(const char *format, int *index, va_list list)
{
	int width = 1;

	if (format[*index] == '*')
	{
		width = va_arg(list, int);
		(*index)++;
	}
	else
	{
		while (format[*index] >= '0' && format[*index] <= '9')
		{
			width = width * 10 + (format[*index] - '0');
			(*index)++
		}
	}
	return (width);
}
