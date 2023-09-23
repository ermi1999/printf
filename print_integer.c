#include "main.h"

/**
 * print_integer - Prints an integer
 * @n: The integer to print
 * @count: Pointer to the count of characters printed
 */
void print_integer(int n, int *count)
{
	char buffer[12];
	int i;
	int length = 0;

	if (n < 0)
	{
		print_char('-', count);
		n = -n;
	}

	do {
		buffer[length++] = '0' + (n % 10);
		n /= 10;
	} while (n > 0);

	for (i = length - 1; i >= 0; i--)
	{
		print_char(buffer[i], count);
	}
}
