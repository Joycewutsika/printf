#include "main.h"

/**
 * print_pointer - Prints a pointer variable
 * @joy: argument name
 * @buffer: Buffer array
 * @flags: the flags
 * @width: the width
 * @precision: Precision
 * @size: Size
 * Return: print characters
 */
int print_pointer(va_list joy, char buffer[],
	int flags, int width, int precision, int size)
{
	char add_c = 0, pad_char = ' ';
	int ind = BUFF_SIZE - 2, len = 2, pad_char_start = 1; /* len=2, for '0x' */
	unsigned long num_addr;
	char map_to[] = "0123456789abcdef";
	void *addr = va_arg(joy, void *);

	UNUSED(width);
	UNUSED(size);

	if (addr == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addr = (unsigned long)addr;

	while (num_addr > 0)
	{
		buffer[ind--] = map_to[num_addr % 16];
		num_addr /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad_char  = '0';
	if (flags & F_PLUS)
		add_c = '+', len++;
	else if (flags & F_SPACE)
		add_c = ' ', len++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_ptr(buffer, ind, len,
		width, flags, pad_char, add_c, pad_char_start));
}

/**
 * display_non_print_char- Prints non printable characters
 * @joy: argument list
 * @buffer: Buffer array
 * @flags:  the flags
 * @width: the width
 * @precision: Precision
 * @size: Size
 * Return: characters printed
 */
int display_non_print_char(va_list joy, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = 0, cancel = 0;
	char *str = va_arg(joy, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[k] != '\0')
	{
		if (is_visible(str[k]))
			buffer[k + cancel] = str[k];
		else
			cancel += add_hex_code(str[k], buffer, k + cancel);

		k++;
	}

	buffer[k + cancel] = '\0';

	return (write(1, buffer, k + cancel));
}

/**
 * print_rever - Prints reverse string.
 * @joy: arguments
 * @buffer: Buffer array
 * @flags:  the flags
 * @width: the width
 * @precision: Precision
 * @size: Size
 * Return: Numbers of character
 */

int print_rever(va_list joy, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int p, cancel = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(joy, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (p = 0; str[p]; p++)
		;

	for (p = p - 1; p >= 0; p--)
	{
		char z = str[p];

		write(1, &z, 1);
		cancel++;
	}
	return (cancel);
}

/**
 * print_rot13 - Print a string in rot13.
 * @joy: list of arguments
 * @buffer: Buffer array
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of character
 */
int print_rot13(va_list joy, char buffer[],
	int flags, int width, int precision, int size)
{
	char v;
	char *str;
	unsigned int a, j;
	int cancel = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(joy, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[a])
			{
				v = out[j];
				write(1, &v, 1);
				cancel++;
				break;
			}
		}
		if (!in[j])
		{
			v = str[a];
			write(1, &v, 1);
			cancel++;
		}
	}
	return (cancel);
}

