#include "sort.h"
#include <stdlib.h> /* For NULL */

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 *
 * Return: void.
 * Prints the list after each time two elements are swapped.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *temp_prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return; /* Nothing to sort if list is NULL or has 0 or 1 element */
	}

	current = (*list)->next; /* Start from the second element */

	while (current != NULL)
	{
		temp_prev = current->prev; /* Element in sorted part to compare with */

		/* While current element is smaller than previous, swap them */
		while (temp_prev != NULL && current->n < temp_prev->n)
		{
			/* Perform swap of nodes by re-linking pointers */
			temp_prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = temp_prev;

			current->next = temp_prev;
			current->prev = temp_prev->prev;

			if (temp_prev->prev != NULL)
				temp_prev->prev->next = current;
			else
				*list = current; /* current becomes the new head */

			temp_prev->prev = current;

			print_list(*list); /* Print list after each swap */

			/* Move temp_prev to the node that is now current's previous */
			temp_prev = current->prev;
		}
		current = current->next; /* Move to the next unsorted element */
	}
}
