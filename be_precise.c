#include "main.h"

/**
 * fetch_precision - Computes string precisin
 * @format: string format
 * @i: List of arguments to be printed.
 * @joy: list of arguments.
 *
 * Return: Precision.
 */
int fetch_precision(const char *format, int *i, va_list joy)
{
	int pre_i = *i + 1;
	int precision = -1;

	if (format[pre_i] != '.')
		return (precision);

	precision = 0;

	for (pre_i += 1; format[pre_i] != '\0'; pre_i++)
	{
		if (is_digit(format[pre_i]))
		{
			precision *= 10;
			precision += format[pre_i] - '0';
		}
		else if (format[pre_i] == '*')
		{
			pre_i++;
			precision = va_arg(joy, int);
			break;
		}
		else
			break;
	}

	*i = pre_i - 1;

	return (precision);
}

