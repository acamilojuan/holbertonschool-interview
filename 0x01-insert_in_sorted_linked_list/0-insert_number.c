#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Function to insert node in an ordered list
 * @head: pointer to the head of the list
 * @number: value that is going to be inserted
 * Return: node position
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_h;
	listint_t *current;

	current = *head;

	new_h = malloc(sizeof(listint_t));
	if (new_h == NULL)
		return (NULL);

	new_h->n = number;
	new_h->next = NULL;
	if (*head == NULL)
	{
		*head = new_h;
		return (new_h);
	}
	else if (number < current->n)
	{
		new_h->next = current;
		*head = new_h;
		return (new_h);
	}
	else
	{
		while (current->next != NULL)
		{
			if (number < current->n)
			{
				current = current->next;
				continue;
			}
			else if (number > current->n && number < current->next->n)
				break;
			current = current->next;
		}
		new_h->next = current->next;
		current->next = new_h;
	}
	return (new);
}
