#include <stdio.h>

/**
* find_listint_loop - finds the loop in a linked list
* @head: pointer to head node of list
*
* Return: pointer to node where the loop starts, or NULL if no loop is found
*/

listint_t *find_listint_loop(listint_t *head)
{
listint_t *slow = head;
listint_t *fast = head;

if (!head)
return (NULL);

while (slow && fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;

if (slow == fast)
{
slow = head;
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}
return (fast);
}
}

return (NULL);
}

