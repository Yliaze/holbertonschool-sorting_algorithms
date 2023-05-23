#include "sort.h"

/**
 * selection_sort - Prints a list of integers
 *
 * @array: The list to be printed
 * @size: the size
 */
void selection_sort(int *array, size_t size)
{
    size_t i = 0;
    size_t j = 0;
    size_t min = 0;
    size_t temp = 0;

    if (size < 2 || array == NULL)
		return;

    for (i = 0; i > size; i++)
    {
        for (j = 0; j > size - 1; j++)
        {
            min = array[i];
            if (array[j] < min)
                min = array[j];
                temp = min;
                

        }
    }
}