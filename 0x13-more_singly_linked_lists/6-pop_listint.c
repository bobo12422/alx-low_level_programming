/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: double pointer to the head node of the linked list
 *
 * Return: the head node's data (n), or 0 if the linked list is empty
 */
int pop_listint(listint_t **head)
{
    int data;
    listint_t *tmp;

    if (*head == NULL)
        return (0);

    tmp = *head;
    *head = (*head)->next;
    data = tmp->n;
    free(tmp);

    return (data);
}

