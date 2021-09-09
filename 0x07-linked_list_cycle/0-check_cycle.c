#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if cycle in linked list
 * @list: pointer to the head of list
 * Return: 0 if no cycle - 1 if cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *check2 = list, *check1 = list;

	while (check2 && check1 && check1->next)
	{
		check2 = check2->next;
		check1 = check1->next->next;
		if (check2 == check1)
		{
			return (1);
		}
	}
	return (0);
}
