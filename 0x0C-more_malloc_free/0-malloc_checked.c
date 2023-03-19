#include <stdlib.h>

#include "main.h"
/**
 * malloc_checked - allocates memory using malloc and checks for errors
 * @b: the number of bytes to allocate
 *
 * Return: a pointer to the allocated memory
 *         exits with status 98 on failure
 */
void *malloc_checked(unsigned int b)

{

	void *ptr;


	ptr = malloc(b);


	if (ptr == NULL)

		exit(98);


	return (ptr);

}
