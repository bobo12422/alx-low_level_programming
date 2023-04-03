#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>
#include <stdio.h>

/* structure declaration for singly-linked list */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* function prototype for printing all the elements of a list */

size_t print_listint(const listint_t *h);
size_t listint_len(const listint_t *h);

#endif /* LISTS_H */
