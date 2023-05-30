#include "main.h"

/**
 * fetch_width - Calculates the width for printing
 * @format: Format string
 * @i: number of argument
 * @joy: arguments.
 *
 * Return: width.
 */
int fetch_width(const char *format, int *i, va_list joy)
{
	int pre_i;
	int width = 0;

	for (pre_i = *i + 1; format[pre_i] != '\0'; pre_i++)
	{
		if (is_digit(format[pre_i]))
		{
			width *= 10;
			width += format[pre_i] - '0';
		}
		else if (format[pre_i] == '*')
		{
			pre_i++;
			width = va_arg(joy, int);
			break;
		}
		else
			break;
	}

	*i = pre_i - 1;

	return (width);
}

