#include "main.h"
#include <stdlib.h>

/**
* create_array - creates an array of size 'size' and initializes each element
*                with the character 'c'
* @size: size of the array to create
* @c: character to initialize each element of the array with
*
* Return: pointer to the created array, or NULL if failed to allocate memory
*/
char *create_array(unsigned int size, char c)
{
char *str;
unsigned int i;

str = malloc(sizeof(char) * size);
if (size == 0 || str == NULL)
return (NULL);

for (i = 0; i < size; i++)
str[i] = c;

return (str);
}

