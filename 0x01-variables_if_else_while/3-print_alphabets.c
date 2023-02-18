#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program prints the lowercase and uppercase alphabet
 *
 * Return: Always 0 (success)
 **/
int main(void)
{
	int i;

	for (i = 'a'; i <= 'z'; i++)
	{
		putchar(i);
	}
	for (i = 'A'; i <= 'Z'; i++)
	{
		putchar(i);
	}
	putchar('\n');

	return (0);
}
