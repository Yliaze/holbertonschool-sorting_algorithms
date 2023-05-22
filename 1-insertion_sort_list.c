#include "sort.h"

/**
 * insertion_sort_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *temp = NULL;

    while (*list != NULL)
    {
        if ((*list)->prev != NULL)
        {
            if ((*list)->n < (*list)->prev->n)
            {
                temp = (*list)->prev->prev;
                (*list)->prev->next = (*list)->next;
                (*list)->prev->prev = *list;
                (*list)->prev = temp;
                (*list)->next = temp->next;
                temp->next = *list;
                print_list(*list);
            }
        }
        *list = (*list)->next;
    }
}
