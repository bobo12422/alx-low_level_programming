#include "lists.h"

/**
* free_listint2 - Frees a listint_t list and sets head to NULL
* @head: Pointer to pointer to the beginning of the list
*/
void free_listint2(listint_t **head)
{
listint_t *temp;

if (head == NULL)
return;

while (*head)
{
temp = (*head)->next;
free(*head);
*head = temp;
}
}

