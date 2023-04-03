#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to the head node of the list.
 * @index: Index of the node to return.
 *
 * Return: If the node exists - pointer to the nth node.
 *         If the node does not exist - NULL.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		if (i == index)
			return (current);
		i++;
		current = current->next;
	}

	return (NULL);
}

