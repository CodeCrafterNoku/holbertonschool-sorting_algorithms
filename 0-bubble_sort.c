#include "sort.h"
#include <stdio.h> /* For print_array prototype if not in sort.h explicitly */

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 *
 * Return: void.
 * Prints the array after each time two elements are swapped.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0; /* Flag to optimize: if no swaps, array is sorted */
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1; /* Mark that a swap occurred */

				/* Print the array after each swap */
				print_array(array, size);
			}
		}
		/* If no elements were swapped in this pass, the array is sorted */
		if (swapped == 0)
		{
			break;
		}
	}
}
