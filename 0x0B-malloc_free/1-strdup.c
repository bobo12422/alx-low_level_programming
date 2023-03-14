#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - create a new string containing a duplicate of an existing string
 * @str: pointer to the string to duplicate
 *
 * Return: pointer to the new string, or NULL if memory allocation fails
 */
char *_strdup(char *str)
{
	char *dup_str;
	int str_len, i;

	if (str == NULL)
		return (NULL);

	str_len = 0;
	while (str[str_len] != '\0')
		str_len++;

	dup_str = malloc(sizeof(char) * (str_len + 1));

	if (dup_str == NULL)
		return (NULL);

	for (i = 0; i <= str_len; i++)
		dup_str[i] = str[i];

	return (dup_str);
}

