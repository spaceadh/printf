#include "main.h"

/**
 * _printf - This function produces output according to a format.
 * @format: The character string
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	int g, print = 0, printed = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (g = 0; format && format[g] != '\0'; g++)
	{
		if (format[g] != '%')
		{
			buffer[buff_ind++] = format[g];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			print++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &g);
			width = get_width(format, &g, list);
			precision = get_precision(format, &g, list);
			size = get_size(format, &g);
			++g;
			print = handle_print(format, &g, list, buffer, flags, width, precision,
					size);
			if (print == -1)
				return (-1);
			printed += print;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(list);

	return (printed);
}

/**
 * print_buffer - prints the contents of the buffer if it exists
 * @buffer: Array of characters
 * buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
