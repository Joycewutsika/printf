#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Prints a fucntion
 * @format: format
 * Return: Printed characters
 */
int _printf(const char *format, ...)
{
	int x, output = 0, output_chars = 0
	int flags, width, precision, size, buff_ind = 0;

	va_list joy
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(joy, format);

	for (x = 0; format && format[i] != '\0'; i++)
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[x], 1);*/
			output_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = fetch_flags(format, &x);
			width = fetch_width(format, &x, joy);
			precision = fetch_precision(format, &x, joy);
			size = fetch_size(format, &x);
			++x;
			output = process_printt(format, &x, joy, buffer,
				flags, width, precision, size);
			if (output == -1)
				return (-1);
			output_chars += output;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(joy);

	return (output_chars);
}

/**
 * print_buffer - Prints buffer content
 * @buffer: character array
 * @buff_ind: Index of buffer
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

