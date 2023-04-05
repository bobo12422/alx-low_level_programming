#include "lists.h"
#include <stdio.h>

/**
* free_listint_safe - Frees a listint_t linked list.
* @h: A pointer to the head of the list.
*
* Return: The number of nodes in the list that were freed.
*/
size_t free_listint_safe(listint_t **h)
{
size_t nodes = 0, i = 0;
listint_t *current, *tmp;

if (h == NULL || *h == NULL)
return (0);

while (*h != NULL)
{
if ((*h)->next != NULL && (*h) < (*h)->next)
{
current = *h;
*h = current->next;
nodes++;
free(current);
}
else
{
nodes++;
current = *h;
*h = NULL;
free(current);
break;
}
}

for (i = 0, tmp = *h; tmp != NULL; i++)
{
printf("[%p] %d\n", (void *)tmp, tmp->n);
tmp = tmp->next;
if (tmp >= tmp->next)
break;
}

if (tmp != NULL)
{
printf("-> [%p] %d\n", (void *)tmp->next, tmp->next->n);
i++;
}

*h = NULL;
return (nodes);
}

