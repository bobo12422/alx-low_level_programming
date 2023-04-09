#include "main.h"

/**
* print_binary - prints the binary representation of a number
* @n: the number to print in binary
*/

void print_binary(unsigned long int n)
{
unsigned long int mask = 1UL << 63;
int flag = 0;

for (int i = 63; i >= 0; i--)
{
if ((n & mask) == 0 && flag == 1)
{
_putchar('0');
}
else if ((n & mask) != 0)
{
_putchar('1');
flag = 1;
}
mask >>= 1;
}
if (flag == 0)
{
_putchar('0');
}
}

