#include "main.h"
/**
 * process_print - based on its type it prints an argument
 * @detail: string format specifier
 * @joy: List of arguments
 * @i: ind.
 * @buffer: Buffer array
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: 1 or 2;
 */
int process_print(const char *detail, int *i, va_list joy, char buffer[],
		int flags, int width, int precision, int size)
{
	int x, len1 = 0, output_chars = -1;
	detail_t detail_types[] = {
		{"c", print_char}, {"s", print_string}, {"%", print_percent},
		{"i", print_int}, {"d", print_int}, {"b", print_binary},
		{"u", print_unsigned}, {"o", print_octal}, {"x", print_hexadecimal},
		{"X", print_Hex_up}, {"p", print_pointer}, {"S", display_non_print_char},
		{"r", print_rever}, {"R", print_rot13}, {'\0', NULL}
	};
	for (x = 0; detail_types[x].detail != NULL; x++)
	{
		if (detail[*i] == *(detail_types[x].detail))
			return (detail_types[x].fxn(joy, buffer, flags, width, precision, size));
	}

	if (detail_types[x].detail == NULL)
	{
		if (detail[*i] == '\0')
			return (-1);
		len1 += write(1, "%%", 1);
		if (detail[*i - 1] == ' ')
			len1 += write(1, " ", 1);
		else if (width)
		{
			--(*i);
			while (detail[*i] != ' ' && detail[*i] != '%')
				--(*i);
			if (detail[*i] == ' ')
				--(*i);
			return (1);
		}
		len1 += write(1, &detail[*i], 1);
		return (len1);
	}
	return (output_chars);
}
