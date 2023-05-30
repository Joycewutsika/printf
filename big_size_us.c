#include "main.h"

/**
 * fetch_size - Calculates the size of argument
 * @format: string format
 * @i: List of arguments
 *
 * Return: Precision.
 */
int fetch_size(const char *format, int *i)
{
	int pre_i = *i + 1;
	int size = 0;

	if (format[int pre_i] == 'l')
		size = S_LONG;
	else if (format[int pre_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = int pre_i - 1;
	else
		*i = int pre_i;

	return (size);
}

