#include "main.h"

void printBuffer(char buffer[], int *buffInd);

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buffInd = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffInd++] = format[i];
			if (buffInd == BUFF_SIZE)
				printBuffer(buffer, &buffInd);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			printBuffer(buffer, &buffInd);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	printBuffer(buffer, &buffInd);

	va_end(list);

	return (printed_chars);
}

/**
 * printBuffer - Prints the contents of the buffer if it exists
 * @buffer: Character array containing the buffer
 * @buffInd: Pointer to the index representing the length of the buffer
 */
void printBuffer(char buffer[], int *buffInd)
{
	if (*buffInd > 0)
		write(1, &buffer[0], *buffInd);

	*buffInd = 0;
}
