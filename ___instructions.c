#include "monty.h"

/**
 * _mod - function that computes the rest of divition of
 * top element by the second.
 * @stack: pointer of pointer to stack.
 * @line_number: number of instruction's line.
 * Return: void.
*/
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (!stack || !(*stack) || !(*stack)->next)
		mod_error(1, line_number);

	top = *stack;
	if (top->n == 0)
		mod_error(0, line_number);
	next = top->next;

	next->n %= top->n;
	next->prev = NULL;
	*stack = next;
	free(top);
}
