#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define S_SHORT 1
#define S_LONG 2

#define F_SPACE 16
#define F_ZERO 4
#define F_MINUS 1
#define F_PLUS 2
#define F_HASH 8

/**
 * struct detail - it maps the conversion specifier for printf
 *
 * @detail: The specifer format.
 * @fxn: The function associated.
 */
struct detail
{
	char *detail;
	int (*fxn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct detail detail_t - it maps the conversion specifier for printf
 *
 * @detail: The format specifier
 * @detail_t: The function associated.
 */
typedef struct detail detail_t;

/* functions to print char and string */
int print_char(va_list joy, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list joy, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list joy, char buffer[],
	int flags, int width, int precision, int size);
int print_int(va_list joy, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list joy, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list joy, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list joy, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list joy, char buffer[],
	int flags, int width, int precision, int size);
int print_Hex_up(va_list joy, char buffer[],
	int flags, int width, int precision, int size);
int print_hex(va_list joy, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int display_non_print_char(va_list joy, char buffer[],
	int flags, int width, int precision, int size);
int print_pointer(va_list joy, char buffer[],
	int flags, int width, int precision, int size);
int print_rever(va_list joy, char buffer[],
	int flags, int width, int precision, int size);
int print_rot13(va_list joy, char buffer[],
	int flags, int width, int precision, int size);
int process_print(const char *detail, int *i,
va_list joy, char buffer[], int flags, int width, int precision, int size);
int write_ptr(char buffer[], int ind, int len,
	int width, int flags, char pad_char, char add_c, int pad_char_start);
int print_num(int ind, char bff[], int flags, int width, int precision,
	int len, char pad_char, char add_c);
int print_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int process_output_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int unsigned_to_string(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);
int add_hex_code(char, char[], int);
int is_visible(char);
int is_digit(char);
int fetch_flags(const char *format, int *i);
int fetch_width(const char *format, int *i, va_list joy);
int fetch_precision(const char *format, int *i, va_list joy);
int fetch_size(const char *format, int *i);

int _printf(const char *format, ...);

long int convert_size_unsigned(unsigned long int num, int size);
long int convert_size_number(long int num, int size);

#endif
