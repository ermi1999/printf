#include "main.h"

/**
 * print_char - Prints a character
 * @c: The character to print
 * @count: Pointer to the count of characters printed
 */
void print_char(char c, int *count)
{
	write(1, &c, sizeof(char));
	(*count)++;
}
