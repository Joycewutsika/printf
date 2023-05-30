#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @joy: rguments name
 * @buffer: Buffer array
 * @flags:  flag
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: character
 */
int print_unsigned(va_list joy, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(joy, unsigned long int);

	fig = convert_size_unsigned int(fig, size);

	if (fig == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (fig > 0)
	{
		buffer[x--] = (fig % 10) + '0';
		fig /= 10;
	}

	x++;

	return (unsigned_to_string(0, x, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned number in octal.
 * @joy: argument name
 * @buffer: Buffer array
 * @flags:  flags available
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: number
 */
int print_octal(va_list joy, char buffer[],
	int flags, int width, int precision, int size)
{

	int g = BUFF_SIZE - 2;
	unsigned long int num = va_arg(joy, unsigned long int);
	unsigned long int init_num = fig;

	UNUSED(width);

	fig = convert_size_unsigned int(fig, size);

	if (fig == 0)
		buffer[g--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (fig > 0)
	{
		buffer[g--] = (fig % 8) + '0';
		fig /= 8;
	}

	if (flags & F_HASH && init_fig != 0)
		buffer[g--] = '0';

	g++;

	return (unsigned_to_string(0, g, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal
 * @joy: argument name
 * @buffer: Buffer array
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number
 */
int print_hexadecimal(va_list joy, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(joy, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_Hex_up - Prints an unsigned number in upper hexadecimal
 * @joy: List of arguments
 * @buffer: Buffer array
 * @flags:  flags active
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of character printed
 */
int print_Hex_up(va_list joy, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(joy, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hex - Prints a hexadecimal number in lower or upper
 * @joy: argument type
 * @map_to: Array of values
 * @buffer: Buffer array
 * @flags: flags active
 * @flag_ch: active flags
 * @width:width
 * @precision: Precision
 * @size: Size
 * @size: Size
 * Return: Number of characters printed
 */
int print_hexa(va_list joy, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int m = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = fig;

	UNUSED(width);

	fig = convert_size_unsgnd(fig, size);

	if (fig == 0)
		buffer[m--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (fig > 0)
	{
		buffer[m--] = map_to[fig % 16];
		fig /= 16;
	}

	if (flags & F_HASH && init_fig != 0)
	{
		buffer[m--] = flag_ch;
		buffer[m--] = '0';
	}

	i++;

	return (unsigned_to_string(0, m, buffer, flags, width, precision, size));
}

