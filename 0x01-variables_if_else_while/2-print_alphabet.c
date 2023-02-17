#include <stdio.h>
/* betty style doc for function main goes there */
/**
 * main - Entry point of the program
 *
 * This function prints the alphabet in lowercase and then in uppercase.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char c = 'a';
    while (c <= 'z')
    {
        putchar(c);
        c++;
    }
    putchar('\n');
    return (0);
}

