#include "monty.h"

/**
 * insert_start - function that insert a node to start of a doubly linked list
 * @head: pointer of pointer to the head of the linked list.
 * @data: data of node.
 * Return: the address of the new node, NULL if it failed.
 */
stack_t *insert_start(stack_t **head, int data)
{
	stack_t *tmp, *p = *head;

	if (head == NULL)
		return (NULL);

	tmp = (stack_t *) malloc(sizeof(stack_t *));
	if (tmp == NULL)
		malloc_error();
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->n = data;

	if (p == NULL)
	{
		*head = tmp;
		return (tmp);
	}

	tmp->next = p;
	p->prev = tmp;
	*head = tmp;
	return (tmp);
}
