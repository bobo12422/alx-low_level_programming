#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
* print_dog - prints a struct dog
* @d: struct dog to print
*
* Description: This function prints out the information of a dog
* struct, including its name, age, and owner. If any of the values are
* NULL, it will print "(nil)" instead.
*/
void print_dog(struct dog *d)
{
if (d == NULL)
return;

if (d->name == NULL)
d->name = "(nil)";
if (d->owner == NULL)
d->owner = "(nil)";

printf("Name: %s\nAge: %f\nOwner: %s\n", d->name, d->age, d->owner);
}

