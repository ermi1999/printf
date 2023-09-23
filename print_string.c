#include "main.h"

/**
 * print_string - Prints a string
 * @str: The string to print
 * @count: Pointer to the count of characters printed
 */
void print_string(const char *str, int *count)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(1, str, len);
	(*count) += len;
}
