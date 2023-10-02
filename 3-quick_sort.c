#include <stdio.h>
#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Changes the positions of two integers in an array.
 * @a: The first integer to switch.
 * @b: The second integer to switch.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Divides an array into two parts for Quick Sort.
 * @array: The array to be split.
 * @size: The number of elements in the array.
 * @left: The leftmost index of the part.
 * @right: The rightmost index of the part.
 *
 * Return: The final index of the pivot element.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot = array + right;
	int i = left - 1;

	for (int j = left; j <= right - 1; j++)
	{
		if (array[j] < *pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(array + i, array + j);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] > *pivot)
	{
		swap_ints(array + (i + 1), pivot);
		print_array(array, size);

	}

	return (i + 1);
}

/**
 * lomuto_sort - A recursive function that sorts an array using Quick Sort.
 * @array: The array to be arranged..
 * @size: The number of elements in the array.
 * @left: The leftmost index of the part.
 * @right: The rightmost index of the part.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	if (left < right)
	{
		int pivot = lomuto_partition(array, size, left, right);

		lomuto_sort(array, size, left, pivot - 1);
		lomuto_sort(array, size, pivot + 1, right);
	}
}


/**
 * quick_sort - Arranges an array of integers in ascending
 * @array: The array to be organized.
 * @size: The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
