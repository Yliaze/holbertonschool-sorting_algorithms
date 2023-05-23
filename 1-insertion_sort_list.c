#include "sort.h"

/**
 * insertion_sort_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;

	while (current != NULL)
	{
		listint_t *insertion_point = current->prev;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			insertion_point->next = current->next;
			if (current->next != NULL)
				current->next->prev = insertion_point;

			current->prev = insertion_point->prev;
			current->next = insertion_point;
			insertion_point->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			insertion_point = current->prev;
			print_list(*list);
		}

		current = current->next;
	}
}
