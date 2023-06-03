#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * get_precision: Get the precision spec
 * iified in the format string.
 * @format: format string.
 * @index:  Pointer to the current position in the format string.
 * @list: Va_list for arguments in variab
 * les.
 * Return: precision value.
 */
int get_precision(const char *format, int *index, va_list list)
{
	int precision = -1;

	if (format[*index] == '*')
	{
		(*index)++;
		if (format[*index] == '*')
		{
			precision = va_arg(list, int);
			(*index)++;
		}
		else
		{
			precision = 0;
			while (format[*index] >= '0' && format[*index] <= '9')
			{
				precision = precision * 10 + (format[*indexi] - '0');
				(*index)++;
			}
		}
	}
	return (precision);
}
