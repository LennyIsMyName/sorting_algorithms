#include "sort.h"

/**
 * insertion_sort_list - this sorts a list using the insertion method.
 * @list: the head of the list to be sorted
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *prev, *current;
	/* If the list is empty or has only one node, it is already sorted */
	if (*list == NULL || (*list)->next == NULL)
		return;
	/* Traverse the list starting from the second node */
	current = (*list)->next;
	while (current != NULL)
	{
	/* Save the current node and its previous node */
	temp = current;
	prev = current->prev;

	/* Find the correct position for the current node in the sorted part of the list */
	while (prev != NULL && prev->n > temp->n)
		prev = prev->prev;

	/* If the current node is already in the correct position, move on to the next node */
	if (prev == temp->prev)
	{
		current = current->next;
	}
	else
	{
		/* Remove the current node from its current position */
		if (temp->prev != NULL)
			temp->prev->next = temp->next;
		else
			*list = temp->next;

		if (temp->next != NULL)
			temp->next->prev = temp->prev;

		/* Insert the current node into the correct position */
		if (prev == NULL)
		{
			temp->next = *list;
			temp->prev = NULL;
			(*list)->prev = temp;
			*list = temp;
		}
		else
		{
			temp->next = prev->next;
			temp->prev = prev;
			if (prev->next != NULL)
			{
				prev->next->prev = temp;
				prev->next = temp;
			}
		}

		/* Move on to the next node */
		current = temp->next;
	}
	print_list(*list);
}
}


