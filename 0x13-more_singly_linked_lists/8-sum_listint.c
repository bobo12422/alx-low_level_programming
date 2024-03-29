#include "lists.h"
/**
* sum_listint - returns the sum of all the data (n) of a listint_t linked list.
* @head: pointer to head of the linked list
*
* Return: sum of all the data (n) of the linked list, 0 if the list is empty
*/
int sum_listint(listint_t *head)
{
int sum = 0;

while (head != NULL)
{
sum += head->n;
head = head->next;
}

return (sum);
}

