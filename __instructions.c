#include "monty.h"

/**
 * _add - function that add top two numbers of stack to each other
 * and inserts the result as top instread of them.
 * @stack: pointer of pointer to stack.
 * @line_number: number of current instruction's line.
 * Return: void.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *next;

	if (!stack || !(*stack) || !(*stack)->next)
		add_error(line_number);

	top = *stack;
	next = top->next;
	next->n += top->n;
	*stack = next;
	free(top);
}