#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: double linked list to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
 *swap_node - swaps a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a ptr to a node which was entered
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *cur = node;

	back->next = cur->next;
	if (cur->next)
		cur->next->prev = back;
	cur->next = back;
	cur->prev = back->prev;
	back->prev = cur;
	if (cur->prev)
		cur->prev->next = cur;
	else
		*list = cur;
	return (cur);
}
