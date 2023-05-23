#include "sort.h"

/**
 * partition - Effectue la partitionnement du tableau
 * en utilisant le schéma de partition de Lomuto
 *
 * @array: Tableau à trier
 * @low: Index de début de la partition
 * @high: Index de fin de la partition
 * @size: size of the array
 *
 * Return: Index du pivot après le partitionnement
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int i = low - 1, temp = 0, j = 0;

	pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_helper - Fonction auxiliaire récursive
 * pour effectuer le tri rapide
 * en utilisant le schéma de partition de Lomuto
 *
 * @array: Tableau à trier
 * @low: Index de début de la partition
 * @high: Index de fin de la partition
 * @size: size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);

		quick_sort_helper(array, low, pivot_index - 1, size);
		quick_sort_helper(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Trie un tableau d'entiers en utilisant
 * l'algorithme de tri rapide avec le schéma de partition
 * de Lomuto
 *
 * @array: Tableau à trier
 * @size: Taille du tableau
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
