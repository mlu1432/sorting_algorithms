#include "sort.h"
#include <stdio.h>

/**
 * swap_ints - Exchange the values of two integers in an array..
 * @a: The first integer to exchange
 * @b: The second integer to exchange
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Arrange an array of integers in ascending order.
 * @array: An array of integers to arrange.
 * @size: The size of the array.
 *
 * Description:  Prints the array after each exchange.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
	return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
		break;
	}
}
