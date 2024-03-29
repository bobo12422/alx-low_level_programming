#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
* print_listint_safe - Prints a listint_t linked list.
* @head: Pointer to the head node of the list.
*
* Return: The number of nodes in the list.
*/

size_t print_listint_safe(const listint_t *head)
{
const listint_t *tortoise, *hare;
size_t nodes = 0, index = 0;

if (head == NULL)
return (0);

nodes = looped_listint_len(head);

if (nodes > 0)
{
tortoise = hare = head;
while (nodes--)
hare = hare->next;

while (tortoise != hare)
{
tortoise = tortoise->next;
hare = hare->next;
}

nodes = 1;
tortoise = tortoise->next;
while (tortoise != hare)
{
nodes++;
tortoise = tortoise->next;
}

printf("[%p] %d\n", (void *)head, head->n);
for (index = 0; index < nodes - 1; index++)
{
head = head->next;
printf("[%p] %d\n", (void *)head, head->n);
}
printf("-> [%p] %d\n", (void *)head->next, head->next->n);
}
else
{
for (; head != NULL; nodes++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
}

return (nodes);
}

/**
* looped_listint_len - Counts the number of unique nodes
* in a looped listint_t linked list.
* @head: A pointer to the head of the listint_t to check.
*
* Return: If the list is not looped - 0.
* Otherwise - the number of unique nodes in the list.
*/

size_t looped_listint_len(const listint_t *head)
{
const listint_t *tortoise, *hare;
size_t nodes = 0;

if (head == NULL || head->next == NULL)
return (0);

tortoise = hare = head;
while (tortoise && hare && hare->next)
{
tortoise = tortoise->next;
hare = hare->next->next;
if (tortoise == hare)
{
tortoise = tortoise->next;
nodes++;
while (tortoise != hare)
{
tortoise = tortoise->next;
nodes++;
}
return (nodes);
}
}

return (0);
}

