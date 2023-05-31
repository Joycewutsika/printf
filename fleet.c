#include "main.h"
/**
 * process_print - Prints an argument based on its type
 * @sym: format string
 * @ind: ind.
 * @joy: arguments list
 * @buffer: Buffer
 * @flags: flags
 * @width: width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int process_print(const char *sym, int *ind, va_list joy, char buffer[],
        int flags, int width, int precision, int size)
{
        int x, len1 = 0, output_chars = -1;
        sym_t sym_types[] = {
                {'c', print_char}, {'s', print_string}, {'%', print_percent},
                {'i', print_int}, {'d', print_int}, {'b', print_binary},
                {'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
                {'X', print_Hex_up}, {'p', print_pointer}, {'S', display_non_print_char},
                {'r', print_rever}, {'R', print_rot13}, {'\0', NULL}
        };
        for (x = 0; sym_types[x].sym != '\0'; x++)
                if (sym[*ind] == sym_types[x].sym)
                        return (sym_types[x].fxn(joy, buffer, flags, width, precision, size));

        if (sym[*ind] == '\0')
        {
                if (sym[*ind] == '\0')
                        return (-1);
                len1 += write(1, "%%", 1);
                if (sym[*ind - 1] == ' ')
                        len1 += write(1, " ", 1);
                else if (width)
                {
                        --(*ind);
                        while (sym[*ind] != ' ' && sym[*ind] != '%')
                                --(*ind);
                        if (sym[*ind] == ' ')
                                --(*ind);
                        return (1);
                }
                len1 += write(1, &sym[*ind], 1);
                return (len1);
        }
        return (output_chars);
}

