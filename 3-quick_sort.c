#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Orders a subset of an array of integers
 *                    according to the lomuto partition scheme
 * @array: The array of integers
 * @size: The size of the array
 * @low: The starting index of the subset
 * @high: The ending index of the subset
 *
 * Return: The final partition index
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] != array[high])
	{
		swap_ints(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_lomuto - Implements the quicksort algorithm through recursion
 * @array: The array of integers to sort
 * @size: The size of the array
 * @low: The starting index of the array partition
 * @high: The ending index of the array partition
 */
void quick_sort_lomuto(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int partition_idx = lomuto_partition(array, size, low, high);

		quick_sort_lomuto(array, size, low, partition_idx - 1);
		quick_sort_lomuto(array, size, partition_idx + 1, high);
	}
}

/**
 * quick_sort - Wrapper function for quicksort
 * @array: The array of integers to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_lomuto(array, size, 0, size - 1);
}
