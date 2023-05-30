#include "main.h"

/**
 * is_visible - Assess if a char is printable
 * @c: Char to be assessed.
 *
 * Return: 1 if c is visible, 0 otherwise
 */
int is_visible(c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * add_hex_code - Add ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int add_hex_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - validate if a char is a digit
 * @c: char to be assessed
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Tosses a number to the specified size
 * @num: Number
 * @size: size of number
 *
 * Return: Tossed value of number
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsigned - Tosses a number to the specified size
 * @num: Number
 * @size: Number of size
 *
 * Return: Tossed value of num
 */
long int convert_size_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

