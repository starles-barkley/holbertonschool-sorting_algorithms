#include "sort.h"
/**
 * insertion_sort_list - insertion sort algorithm
 * @list: doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *new = NULL;
	listint_t *temp = NULL;

	if (*list == NULL || list == NULL)
	{
		return;
	}
	new = *list;
	new = new->next;
	while (new)
	{
		if (new->n < (new->prev)->n)
		{
			temp = new->prev;
			new->prev = temp->prev;
			if (temp->prev != NULL)
				temp->prev->next = new;
			else
				*list = new;
			temp->next = new->next;
			if (new->next != NULL)
				new->next->prev = temp;
			new->next = temp;
			temp->prev = new;
			new = new->next;
			print_list(*list);
		}
		else
			new = new->next;
	}
}
