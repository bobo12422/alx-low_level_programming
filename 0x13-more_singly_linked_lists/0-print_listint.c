#include <stdio.h>
#include "lists.h"

int main(void)
{
    listint_t *head = NULL;
    listint_t *new_node;
    int i;

    for (i = 0; i < 10; i++)
    {
        new_node = malloc(sizeof(listint_t));
        if (new_node == NULL)
        {
            printf("Error: malloc failed\n");
            return (1);
        }
        new_node->n = i;
        new_node->next = head;
        head = new_node;
    }

    printf("Printing list:\n");
    print_listint(head);

    return (0);
}

