#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void)
{
    int i, j;

    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            int res = i * j;
            if (j == 0)
            {
                _putchar('0');
            }
            else if (res < 10)
            {
                _putchar(' ');
                _putchar(res + '0');
            }
            else
            {
                _putchar(res / 10 + '0');
                _putchar(res % 10 + '0');
            }

            if (j != 9)
            {
                _putchar(',');
                _putchar(' ');
            }
        }
        _putchar('\n');
    }
}

