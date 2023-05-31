#include "main.h"

/**
 * print_char - Prints a character
 * @joy: argument list
 * @buffer: Buffer array
 * @flags:  Computes flags
 * @width: Width
 * @precision: the precision
 * @size: the size
 * Return: characters
 */
int print_char(va_list joy, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(joy, int);

	return (process_output_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints a string
 * @joy: argument list
 * @buffer: Buffer array
 * @flags:  available flag
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: character
 */
int print_string(va_list joy, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, x;
	char *str = va_arg(joy, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (*str != '\0')
	{
		len++;
		str++;
	}

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, str, len);
			for (x = width - len; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - len; x > 0; x--)
				write(1, " ", 1);
			write(1, str, len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
 * print_percent - Prints a percentage sign
 * @joy: argument list
 * @buffer: Buffer array
 * @flags:  available flags
 * @width: get width.
 * @precision: Precision
 * @size: Size
 * Return: Number of characters
 */
int print_percent(va_list joy, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(joy);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}


/**
 * print_int - Print integer
 * @joy: arguments
 * @buffer: Buffer array
 * @flags:  active flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: integer
 */
int print_int(va_list joy, char buffer[],
	int flags, int width, int precision, int size)
{
	int m = BUFF_SIZE - 2;
	int is_negative = 0;
	long int z = va_arg(joy, long int);
	unsigned long int num;

	z = convert_size_number(z, size);

	if (z == 0)
		buffer[m--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)z;

	if (z < 0)
	{
		num = (unsigned long int)((-1) * z);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[m--] = (num % 10) + '0';
		num /= 10;
	}

	m++;

	return (print_number(is_negative, m, buffer, flags, width, precision, size));
}


/**
 * print_binary - Prints an unsigned number
 * @joy: argument name
 * @buffer: Buffer
 * @flags: flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: Number.
 */
int print_binary(va_list joy, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int total, f, y, p;
	unsigned int g[32];
	int account;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	f = va_arg(joy, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	g[0] = f / y;
	for (p = 1; p < 32; p++)
	{
		y /= 2;
		g[f] = (f / y) % 2;
	}
	for (p = 0, total = 0, account = 0; p < 32; p++)
	{
		total += g[p];
		if (total || p == 31)
		{
			char z = '0' + g[p];

			write(1, &z, 1);
			account++;
		}
	}
	return (account);
}
