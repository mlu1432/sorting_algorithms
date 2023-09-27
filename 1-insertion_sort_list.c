#include "sort.h"

/**
 * swap_nodes - Exchange the positions of two nodes in
 * a listint_t doubly-linked list.
 * @h:  pointer to the head of the doubly-linked list..
 * @n1: pointer to the first node to exchange.
 * @n2: The second node to exchange.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Arrange a doubly linked list of integers in ascending
 *                       order using the insertion sort algorithm.
 * @list: pointer to the head of a doubly-linked list of integers.
 *
 * Description:  Prints the list after each exchange..
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		sorted = current->prev;
		while (sorted != NULL && current->n < sorted->n)
		{
			swap_nodes(list, &sorted, current);
			print_list((const listint_t *)*list);
		}
	}
}
