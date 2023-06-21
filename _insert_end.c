#include "monty.h"

/**
 * insert_end - function that insert new node to the end of a doubly linkedlist
 * @head: pointer of pointer to the head of a doubly linked list.
 * @data: data of the new node.
 * Return: the address of the new node.
 */
stack_t *insert_end(stack_t **head, int data)
{
	stack_t *p = *head, *tmp;

	if (!head)
		return (NULL);

	tmp = (stack_t *) malloc(sizeof(stack_t *));
	if (!tmp)
		return (NULL);
	tmp->n = data;
	tmp->next = NULL;
	tmp->prev = NULL;

	if (!p)
	{
		*head = tmp;
		return (tmp);
	}

	while (p->next)
		p = p->next;
	p->next = tmp;
	tmp->prev = p;
	return (tmp);
}
