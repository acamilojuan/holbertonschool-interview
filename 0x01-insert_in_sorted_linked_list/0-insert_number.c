#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - Function to insert node in an ordered list
 * @head: pointer to the head of the list
 * @number: value that is going to be inserted
 * Return: node position
 */

listint_t *insert_node(listint_t **head, int number)
{

	listint_t *temp1 = *head;
	listint_t *temp2;
	listint_t *new_h;
	

	new_h = malloc(sizeof(listint_t));

	if (new_h == NULL)
		return (NULL);

	new_h->n = number;

	if (*head == NULL)
	{
		*head = new_h;
		return (new_h);
	}

	if (number < temp1->n)
	{
		new_h->next = *head;
		*head = new_h;
		return (new_h);
	}

	while (temp1->next != NULL)
	{
		if (number < temp1->next->n)
			break;
		temp1 = temp1->next;
	}

	temp2 = temp1->next;
	temp1->next = new_h;
	new_h->next = temp2;
	return (new_h);
}
