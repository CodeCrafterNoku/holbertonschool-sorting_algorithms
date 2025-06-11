#include "sort.h"
#include <stddef.h> /* For size_t */
#include <stdio.h>  /* For print_array */

/**
 * swap_elements - Swaps two elements in an array and prints the array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 * @array: The full array for printing.
 * @size: The size of the full array.
 */
static void swap_elements(int *a, int *b, int *array, size_t size)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, size);
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme for Quick Sort.
 * @array: The array or sub-array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition (pivot element).
 * @size_original: The original size of the full array (for printing).
 *
 * Return: The index of the pivot element after partitioning.
 */
static int lomuto_partition(int *array, int low, int high,
			    size_t size_original)
{
	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j) /* Only swap if elements are different */
			{
				swap_elements(&array[i], &array[j], array, size_original);
			}
		}
	}
	if ((i + 1) != high) /* Only swap if pivot needs to move */
	{
		swap_elements(&array[i + 1], &array[high], array, size_original);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive helper function for Quick Sort.
 * @array: The array or sub-array to be sorted.
 * @low: The starting index of the current sub-array.
 * @high: The ending index of the current sub-array.
 * @size_original: The original size of the full array (for printing).
 */
static void quick_sort_recursive(int *array, int low, int high,
				 size_t size_original)
{
	int pi; /* Partitioning Index */

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size_original);

		quick_sort_recursive(array, low, pi - 1, size_original);
		quick_sort_recursive(array, pi + 1, high, size_original);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition scheme).
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 *
 * Return: void.
 * Prints the array after each time two elements are swapped.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	quick_sort_recursive(array, 0, size - 1, size);
}
