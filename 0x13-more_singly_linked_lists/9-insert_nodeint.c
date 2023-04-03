#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 *
 * @head: Pointer to a pointer to the head node of the list.
 * @idx: Index of the list where the new node should be added.
 * @n: Data of the new node.
 *
 * Return: Address of the new node or NULL if it fails.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current_node = *head;
	unsigned int i;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (!idx)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	for (i = 0; current_node && i < idx - 1; i++)
		current_node = current_node->next;

	if (!current_node)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = current_node->next;
	current_node->next = new_node;

	return (new_node);
}

