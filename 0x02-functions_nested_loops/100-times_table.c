#include "main.h"

/**
 * print_times_table - Prints the n times table, starting with 0.
 *
 * @n: The times table to print.
 */
void print_times_table(int n)
{
	int i, j;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (j == 0)
				_putchar('0');
			else
				_putchar(',');
			_putchar(' ');

			if (i * j < 10)
				_putchar(' ');
			else if (i * j < 100)
				_putchar('0' + (i * j) / 10);

			_putchar('0' + (i * j) % 10);
		}
		_putchar('\n');
	}
}

