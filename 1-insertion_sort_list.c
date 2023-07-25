#include "sort.h"

/**
 * insert_node - Inserts a node in its correct place
 * in a sorted list.
 * @list: pointer to the pointer of the head of a list.
 * @sorted: pointer to the head of the sorted list.
 * @current: pointer to the node to be inserted.
 */
void insert_node(listint_t **list, listint_t **sorted, listint_t *current)
{
	listint_t *temp = *sorted;

	 while (temp != NULL && temp->n < current->n)
		  temp = temp->next;

	 if (temp == NULL)
	 {
		 current->prev = *sorted;
		 current->next = NULL;
		 if (*sorted != NULL)
			 (*sorted)->next = current;
		 *sorted = current;
	 }
	 else
	 {
		 current->prev = temp->prev;
		 current->next = temp;
		 if (temp->prev != NULL)
			 temp->prev->next = current;
		 else
			 *list = current;
		 temp->prev = current;
	 }

	 print_list((const listint_t *)*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion sort.
 * @list: pointer to the pointer of the head of a doubly linked
 * list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next, *prev, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		tmp = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;
			current->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;

			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;

			current->next = prev;
			prev->prev = current;

			print_list(*list);
		}
		current = tmp;
	}
}
