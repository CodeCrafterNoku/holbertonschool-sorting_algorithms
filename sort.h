#ifndef SORT_H
#define SORT_H

#include <stddef.h> /* For size_t */
#include <stdio.h>  /* For printf (used in print_array/print_list) */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Provided printing functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting functions */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 *
 * Return: void.
 */
void selection_sort(int *array, size_t size);

#endif /* SORT_H */
