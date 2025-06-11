#include "sort.h"
#include <stddef.h> /* For size_t */

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 *
 * Return: void.
 * Prints the array after each time two elements are swapped.
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min_idx;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}

	/* Traverse through all array elements */
	for (i = 0; i < size - 1; i++)
	{
		/* Find the minimum element in the unsorted array */
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}

		/* Swap the found minimum element with the first element */
		/* Only swap and print if the minimum is not already in place */
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			print_array(array, size);
		}
	}
}
