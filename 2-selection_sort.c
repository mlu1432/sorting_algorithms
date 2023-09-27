#include "sort.h"

/**
 * swap_ints - Exchange two integers in an array.
 * @a: The first integer to exchange.
 * @b: The second integer to exchange.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Arrange an array of integers in ascending order
 *                  using the selection sort algorithm..
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each exchange.
 */
void selection_sort(int *array, size_t size)
{
	int *min_indx;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_indx = array + i;
		for (j = i + 1; j < size; j++)
			min_indx = (array[j] < *min_indx) ? (array + j) : min_indx;

		if ((array + i) != min_indx)
		{
			swap_ints(array + i, min_indx);
			print_array(array, size);
		}
	}
}
