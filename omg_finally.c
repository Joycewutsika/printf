#include "main.h"

/**
 * process_output_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags: computes active flags.
 * @width: width.
 * @precision: Precision
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int process_output_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int m = 0;
	char pad_char = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pad_char = '0';

	buffer[m++] = c;
	buffer[m] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		while (m < width - 1)
			m++;
		buffer[BUFF_SIZE - m - 2] = pad_char;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - m - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - m - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * print_number - Print a string
 * @is_negative: List of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Computes active flags
 * @width: Fetch width.
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int print_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char pad_char = ' ', add_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad_char = '0';
	if (is_negative)
		add_ch = '-';
	else if (flags & F_PLUS)
		add_ch = '+';
	else if (flags & F_SPACE)
		add_ch = ' ';

	return (print_num(ind, buffer, flags, width, precision,
		len, pad_char, add_ch));
}

/**
 * print_num - Write a number
 * @ind: Index at which the number starts on the buffer
 * @buff: Buffer
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @len: Number length
 * @pad_char: Padding char
 * @add_c: additional char
 *
 * Return: Number of printed chars.
 */
int print_num(int ind, char bff[],
	int flags, int width, int precision,
	int len, char pad_char, char add_c)
{
	int m, pad_char_start = 1;

	if (precision == 0 && ind == BUFF_SIZE - 2 && bff[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (precision == 0 && ind == BUFF_SIZE - 2 && bff[ind] == '0')
		bff[ind] = pad_char = ' ';
	if (precision > 0 && precision < len)
		pad_char = ' ';
	while (precision > len)
		bff[--ind] = '0', len++;
	if (add_c != 0)
		len++;
	if (width > len)
	{
		while (m < width - len + 1)
		{
			m++;
		}
			bff[m] = pad_char;
		bff[m] = '\0';
		if (flags & F_MINUS && pad_char == ' ')
		{
			if (add_c)
				bff[--ind] = add_c;
			return (write(1, &bff[ind], len) + write(1, &bff[1], m - 1));
		}
		else if (!(flags & F_MINUS) && pad_char == ' ')
		{
			if (add_c)
				bff[--ind] = add_c;
			return (write(1, &bff[1], m - 1) + write(1, &bff[ind], len));
		}
		else if (!(flags & F_MINUS) && pad_char == '0')
		{
			if (add_c)
				bff[--pad_char_start] = add_c;
			return (write(1, &bff[pad_char_start], m - pad_char_start) +
				write(1, &bff[ind], len - (1 - pad_char_start)));
		}
	}
	if (add_c)
		bff[--ind] = add_c;
	return (write(1, &bff[ind], len));
}

/**
 * unsigned_to_string - Writes an unsigned number
 * @is_negative: checks if number is negative
 * @ind: Index
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int unsigned_to_string(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, m = 0;
	char pad_char = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < length)
		pad_char = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad_char = '0';

	if (width > length)
	{
		for (m = 0; m < width - length; m++)
			buffer[m] = pad_char;

		buffer[m] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], m));
		}
		else
		{
			return (write(1, &buffer[0], m) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_ptr - Writes memory address
 * @buffer: Arrays of chars
 * @ind: Index
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @pad_char: char representing the padding
 * @add_c: char representing extra char
 * @pad_char_start: start of padding
 *
 * Return: Number of written chars.
 */
int write_ptr(char buffer[], int ind, int len,
	int width, int flags, char pad_char, char add_c, int pad_char_start)
{
	int m;

	if (width > len)
	{
		for (m = 3; m < width - len + 3; m++)
			buffer[m] = pad_char;
		buffer[m] = '\0';
		if (flags & F_MINUS && pad_char == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (add_c)
				buffer[--ind] = add_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], m - 3));
		}
		else if (!(flags & F_MINUS) && pad_char == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (add_c)
				buffer[--ind] = add_c;
			return (write(1, &buffer[3], m - 3) + write(1, &buffer[ind], len));
		}
		else if (!(flags & F_MINUS) && pad_char == '0')
		{
			if (add_c)
				buffer[--pad_char_start] = add_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_char_start], m - pad_char_start) +
				write(1, &buffer[ind], len - (1 - pad_char_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (add_c)
		buffer[--ind] = add_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

