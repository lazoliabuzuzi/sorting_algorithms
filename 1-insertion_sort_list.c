#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list.
 * @list: pointer to the pointer of the head of the list.
 * @node1: the first node to be swapped.
 * @node2: the second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: pointer to the pointer of the head of a doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL, *current = *list, *next_node = NULL, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		next_node = current->next;

		if (sorted == NULL || sorted->n >= current->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			temp = sorted;
			
			while (temp != NULL && temp->n < current->n)
				temp = temp->next;

			if (temp == NULL)
			{
				current->prev = sorted;
				current->next = NULL;
				sorted->next = current;
			}
			else
			{
				current->prev = temp->prev;
				current->next = temp;
				if (temp->prev)
					temp->prev->next = current;
				temp->prev = current;
			}
		}

		print_list(*list);
		current = next_node;
	}

	*list = sorted;
}
