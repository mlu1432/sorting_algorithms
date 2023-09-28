#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - prints an array of integers,
 *	followed by a new line
 * @array: pointer to the first element of
 i*	the array to be printed
 * @size: the number of elements in the array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
