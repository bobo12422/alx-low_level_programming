#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program prints the lowercase alphabet, then the
 * uppercase alphabet, followed by a newline character, using only the
 * putchar function.
 *
 * Return: Always 0 (success)
 **/
int main(void)
{
    char c;

    /* Print lowercase alphabet */
    for (c = 'a'; c <= 'z'; c++)
    {
        putchar(c);
    }

    /* Print uppercase alphabet */
    for (c = 'A'; c <= 'Z'; c++)
    {
        putchar(c);
    }

    /* Print newline character */
    putchar('\n');

    return (0);
}

