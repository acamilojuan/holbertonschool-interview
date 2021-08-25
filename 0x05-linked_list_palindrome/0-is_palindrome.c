#include "lists.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * is_palindrome - checks if linked list's palindrome
 * @head: pointer to head of the list
 * Return: 0 if !palindrome - 1 if palindrome
 */
int is_palindrome(listint_t **head)
{

		listint_t *aux = NULL;
		int *array = NULL;
		int a = 0;
		int b = 1;
		int count = 1;

		if (head == NULL)
			return (0);
		if (*head == NULL)
			return (1);

		aux = *head;
		while (aux->next != NULL)
		{
			count += 1;
			aux = aux->next;
		}
		array = malloc((count) * sizeof(int));
		aux = *head;
		a = 0;
		while (aux->next != NULL)
		{
			array[a] = aux->n;
			aux = aux->next;
			a++;
		}
		array[a] = aux->n;

		a = 0;
		while (a < count && b == 1)
		{
		if (array[a] != array[count - 1 - a])
		{
			b = 0;
		}
		a++;
		}
		free(array);
		return (b);
}
