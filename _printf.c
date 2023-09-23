#include "main.h"

/**
 * handle_conversion - Handles the conversion specifier
 * @format: Pointer to the current position in the format string
 * @args: The va_list of arguments
 * @count: Pointer to the count of characters printed
 */
void handle_conversion(const char **format, va_list args, int *count)
{
	(*format)++;

	switch (**format)
	{
		case 'c':
		{
			int arg = va_arg(args, int);

			print_char(arg, count);
			break;
		}
		case 's':
		{
			const char *arg = va_arg(args, const char *);

			print_string(arg, count);
			break;
		}
		case '%':
		{
			char percent = '%';

			print_char(percent, count);
			break;
		}
		default:
			break;
	}
}

/**
 * print_format - Prints the formatted output
 * @format: The format string
 * @args: The va_list of arguments
 * @count: Pointer to the count of characters printed
 */
void print_format(const char *format, va_list args, int *count)
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			handle_conversion(&format, args, count);
		}
		else
		{
			print_char(*format, count);
		}

		format++;
	}
}

/**
 * _printf - Prints formatted output to stdout
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int count;

	va_list args;

	va_start(args, format);

	count = 0;

	print_format(format, args, &count);

	va_end(args);

	return (count);
}
